#include <string>
#include <sstream>
#include <stack>
#include <vector>
#include <memory>
#include "BlocksAndPieces.hpp"
#include "Utility.hpp"
#include "TetrominoFiller.hpp"
#include "pugixml/pugixml.hpp"

using namespace std;
using namespace pugi;

string IntToString(int input)
{
  stringstream ss;
  ss << input;
  return ss.str();
}

vector<vector<shared_ptr<BlockBase > > > buildGrid(int rows, int cols, string gridString)
{
  stringstream ss(gridString);
  int count = 0;
  vector<vector<shared_ptr<BlockBase>>> grid;
  vector<shared_ptr<BlockBase>> gridRow;
  string cell;
  while (ss >> cell) {
    if (cell == "0") {
      gridRow.push_back(make_shared<BlankBlock>(BlankBlock(count / cols, count % cols)));
    }
    else if (cell == "1") {
      gridRow.push_back(make_shared<Block>(Block(count / cols, count % cols, '1')));
    }
    else {
      // TODO: handle the error here
    }
    count++;
    if (count % cols == 0) {
      grid.push_back(gridRow);
      gridRow.clear();
    }
  }

  if (count != rows*cols) {
    // TODO: handle parse error here
  }

  return grid;
}

int GetAttributeAsInt(xml_node &node, string attribute)
{
  stringstream ss(node.attribute(attribute.c_str()).value());
  int result;
  ss >> result;
  return result;
}

void SolutionToXML(xml_document & doc, stack<shared_ptr<PieceBase> > solutionStack, const char * color, const char * boarderColor)
{
  xml_node solution = doc.child("tetrisFill").append_child("solution");
  shared_ptr<PieceBase> piece;
  while (!solutionStack.empty()) {
    piece = solutionStack.top();
    xml_node pieceNode = solution.append_child("piece");
    pieceNode.append_attribute("type") = IntToString(piece->Id()).c_str();
    pieceNode.append_attribute("row") = IntToString(piece->i).c_str();
    pieceNode.append_attribute("col") = IntToString(piece->j).c_str();
    if (color != nullptr) {
      pieceNode.append_attribute("color") = color;
    }
    if (boarderColor != nullptr) {
      pieceNode.append_attribute("boarderColor") = boarderColor;
    }
    solutionStack.pop();
  }  
}

void SolutionToXML(xml_document & doc, stack<shared_ptr<PieceBase> > solutionStack)
{
  SolutionToXML(doc, solutionStack, nullptr, nullptr);
}


void TetrominoFill(xml_document &doc) {
  // Read the problem and build the grid and extract start point
  xml_node problem = doc.child("tetrisFill").child("problem");
  xml_node gridNode = problem.child("grid");
  int gridRows = GetAttributeAsInt(gridNode, "row");
  int gridCols = GetAttributeAsInt(gridNode, "col");
  string gridString = string(gridNode.text().get());
  xml_node start = problem.child("start");
  int startRow = GetAttributeAsInt(start, "row");
  int startCol = GetAttributeAsInt(start, "col");

  vector<vector<shared_ptr<BlockBase > > > grid = buildGrid(gridRows, gridCols, gridString);
  // Pass the grid and start point to the tetris solver alg

  TetrominoFiller filler = TetrominoFiller(&grid);
  filler.fill(startRow, startCol);

  // Get the solution stack and write to xml object
  stack<shared_ptr<PieceBase> > solutionStack = filler.getSolutionStack();
  SolutionToXML(doc, solutionStack);
}  

// Function to take a tetris fill puzzle and create a solution
string TetrominoFillString(string input)
{
  // De-searilize string into xml object
  xml_document doc;
  doc.load(input.c_str());
  
  TetrominoFill(doc);
  
  // Searialize xml object back into string and return
  stringstream ss;
  doc.save(ss);
  return ss.str();
}

void TetrominoFillFile(string filePath)
{
  xml_document doc;
  doc.load_file(filePath.c_str());
  TetrominoFill(doc);
  doc.save_file(filePath.c_str());
}

// Method takes an array of strings representing a grid
vector<vector<shared_ptr<BlockBase > > > buildProblemFromXPM(int gridRows, int gridCols, char * charGrid[], char regionChar) {
  vector<vector<shared_ptr<BlockBase > > > blockGrid;
    
  char * charRow;
  
  for (int i = 0; i < gridRows; i++) {
    
    charRow = charGrid[i];
    vector<shared_ptr<BlockBase> > blockRow;

    for (int j = 0; j < gridCols; j++) {
      if (*(charRow + j) == regionChar) {
        blockRow.push_back(make_shared<BlankBlock>(BlankBlock(i ,j)));
      }
      else {
        blockRow.push_back(make_shared<Block>(Block(i, j, regionChar)));
      }
    }

    blockGrid.push_back(blockRow);
  }

  return blockGrid;
}

class recCounter {
private:
  vector<vector<shared_ptr<BlockBase > > > * grid;
  set<shared_ptr<BlockBase> > blocks;
public:
  recCounter(vector<vector<shared_ptr<BlockBase > > > * g) : grid{g} {}

  int recCount(unsigned int i, unsigned int j) {
    if (!((*grid)[i][j]->isBlank())) return 0;
    if (blocks.find((*grid)[i][j]) != blocks.end()) return 0;
    blocks.insert((*grid)[i][j]);

    int u = 0;
    int d = 0;
    int l = 0;
    int r = 0;
    if (i >= 1) {
      u = recCount(i-1, j);
    }
    if (i+1 < (*grid).size()) {
      d = recCount(i+1, j);
    }
    if (j >= 1) {
      l = recCount(i, j-1);
    }
    if (j+1 < (*grid)[0].size()) {
      r = recCount(i, j+1);
    }
  
    return 1+u+d+l+r;
  }

  bool hasCounted(shared_ptr<BlockBase > block) {
    return (blocks.find(block) != blocks.end());
  }
};

vector<shared_ptr<BlockBase> > selectStartingPoints(vector<vector<shared_ptr<BlockBase > > > & grid) {
  recCounter counter(&grid);

  vector<shared_ptr<BlockBase> > startBlocks;
  
  for (unsigned int i = 0; i < grid.size(); i++) {
    for (unsigned int j = 0; j < grid[0].size(); j++) {
      if (!grid[i][j]->isBlank()) continue;
      if (counter.hasCounted(grid[i][j])) continue;

      startBlocks.push_back(grid[i][j]);

      int count = counter.recCount(i, j);
      
      if (count % 4 != 0) {
        cout << "Error! region at (" << i << ", " << j << ") has count " << count << endl;
      }
    }
  }

  return startBlocks;
}

void TetrominoFillXPM(char * xpm[], xml_document & doc){

  int index = 0;
  
  // First parse the .xpm file format
  stringstream ss (xpm[index++]);
  int gridRows;
  int gridCols;
  int colorCount;
  
  ss >> gridCols;
  ss >> gridRows;
  ss >> colorCount;

  char colorChars[colorCount];
  string colors[colorCount];
  
  // Get the color information (start at 1 to skip ' ' char)
  for (int i = 0; i < colorCount; i++) {
    colorChars[i] = *xpm[index];
    string color = xpm[index++];
    colors[i] = color.substr(color.find('#'));
  }

  char * grid[gridRows];
  
  // Build grid out of the next lines
  for (int i = 0; i < gridRows; i++) {
    grid[i] = xpm[index++];
  }
  // Do the folling in a loop:
  // 1. Find a region
  // 2. create problem grid
  // 3. send it to the solver
  for (int i = 0; i < colorCount; i++) {
    vector<vector<shared_ptr<BlockBase > > > problem = buildProblemFromXPM(gridRows, gridCols, grid, colorChars[i]);
    vector<shared_ptr<BlockBase> > startingPoints = selectStartingPoints(problem);

    // For each starting point, run a solver.
    for (auto block : startingPoints) {
      TetrominoFiller filler = TetrominoFiller(&problem);
      filler.fill(block->i, block->j);
      
      // Get the solution stack and write to xml object
      stack<shared_ptr<PieceBase> > solutionStack = filler.getSolutionStack();

      string white = "white";
      SolutionToXML(doc, solutionStack, colors[i].c_str(), white.c_str());
    }
  }
}

static char * bee_xpm[] = {
"89 144 3 1",
" 	c #FFFFFF",
".	c #000000",
"+	c #FFDD55",
"                                                                                         ",
"                                                                                         ",
"                                                                                         ",
"                                                                                         ",
"                                                                                         ",
"                                                                                         ",
"                                                                                         ",
"                                                                                         ",
"                                                                                         ",
"                                                                                         ",
"                                                                                         ",
"                                                                                         ",
"                                                                                         ",
"                                                                                         ",
"                                                                                         ",
"                                                                                         ",
"                                                                                         ",
"                                                                                         ",
"                                                                                         ",
"                                                                                         ",
"                                                                                         ",
"                                                                                         ",
"                                                                                         ",
"                                                                                         ",
"                                                                                         ",
"                                                                                         ",
"                                                                                         ",
"                                                                                         ",
"                                                                                         ",
"                                                                                         ",
"                                                                                         ",
"                                                                                         ",
"                                                                                         ",
"                                                                                         ",
"                                                              ...                        ",
"                                                              ....                       ",
"                                                              .....                      ",
"                                                              .....                      ",
"                  ....                                        ....                       ",
"                  ......                                     ....                        ",
"                 ........                                    ....                        ",
"                 ........                                    ...                         ",
"                 ........                                    ...                         ",
"                  .......                                    ..                          ",
"                      ...                                    ..                          ",
"                       ..                                   ...                          ",
"                       ...                                  ...                          ",
"                       ...                                  ..                           ",
"                        ..                                 ...                           ",
"                        ...                                ...                           ",
"                        ...                                ..                            ",
"                        ...                                ..                            ",
"                         ..         .................      ..                            ",
"                         ...      .....................   ...                            ",
"                          ..    .........+++++++++....... ...                            ",
"                          ...  .....+++++++++++++++++........                            ",
"                           ........+++++++++++++++++++......                             ",
"                           .......++++++++++++++++++++++....                             ",
"                           ......+++++++++++++++++++++++.....                            ",
"                           .....++++++++++++++++++++++++.....                            ",
"                           ....+++++++++++++++++++++++++.....                            ",
"                           ....+++++++++++++++++++++++++......                           ",
"                           ....+++++++++++++++++++++++++......                           ",
"                           .....++++++++++++++++++++++++..++...                          ",
"                          ......++++++++++++++++++++++++++++...                          ",
"                          ...+++++++++++++++++++++++++++++++...                          ",
"                          ...+++++++++++++++++++++++++++++++...                          ",
"                          ...+++++++++++++++++++++++++++++++...                          ",
"                           ..+++++++++++++++++++++++++++++++...                          ",
"                           ...++++++++++++++++++++++++++++++...                          ",
"                           ...+++++++++++++++++++++++++++++....                          ",
"                           ...++++++++++++++++++++++++++++....                           ",
"                            ...+++++++++++++++++++++++++++....                           ",
"                            ....+++++++++++++++++++++++++.......                         ",
"                            .....++++++++++++++++++++++++.........                       ",
"                            ......++++++++++++++++++++++............                     ",
"                           ........+++++++++++++++++++.....   .......                    ",
"                         ............+++++++++++++++......       .....                   ",
"                       ................++++++++++.........        ......                 ",
"                      ......      ........................          .....                ",
"                    .....        ...................    ...          .....               ",
"                   .....        .... ...............    ....          .....              ",
"                 .....         ....     ...++++....       ...           .....            ",
"                ......        ....      ...++++....       ....           ....            ",
"               .....         ....       ...+++++....       ....     ..    ....           ",
"              .....          ....      ....+++++....        ....   ......  ....          ",
"             .....  ...    ....        ....++++++...         ....  ....... ....          ",
"             .... ......   ....        ...+++++++....         ....   .....  ....         ",
"           .....  .....  ....          ...+++++++....          ....          ...         ",
"           ....   ..     ...           ...++++++++....       .   ...         ....        ",
"          .....          ..           ....++++++++....      ..   ...         ....        ",
"         ....                         ....+++...++.....     ...   ...         ....       ",
"         ....               .        ............+.....     ...   ..           ...       ",
"        ....               ..        ...................     ..    .           ....      ",
"        ...                ..       ....................     ..                ....      ",
"        ...               ...       .....................    ...                ...      ",
"       ....               ..       .......................   ...                ...      ",
"       ...               ...      ...............+++++.....   .                 ...      ",
"      ....               ..      .....+++....++++++++++.....                   .....     ",
"      ....               ..      ....++++++.++++++++++++.....                  ....      ",
"      ....              ..      ....+++++++++++++++++++++.....                ....       ",
"       ...               .     ....+++++++++++++++++++++++.....              .....       ",
"       ...                    ....+++++++++++++++++++++++++.......         ......        ",
"       ....                  .....++++++++++++++++++++++++++.....................        ",
"        ....               ......+++++++..++++++++++++....+++...................         ",
"        .....           .........++++........++++++.......+++................            ",
"         .....        ..........................++.........................              ",
"          ......................................................................         ",
"           ........................................................................      ",
"          ..........................................................   .............     ",
"         .....................................................+.....       .........     ",
"         .........       .........+++++++++++.....++++++++...++....                      ",
"         ......          ....+++++++++++++++++....+++++++++++++....                      ",
"                         ....++++++++++++++++++..++++++++++++++...                       ",
"                          ...++++++++++++++++++++++++++++++++++...                       ",
"                          ...++++++++++++++++++++++++++++++++++...                       ",
"                          ...++++++++++++++....+++++......++++.....                      ",
"                          ....+++++++++..........++........+++.........                  ",
"                       ........++...........................+................            ",
"                      .........................................................          ",
"                    .............................................     ..........         ",
"                    .....   ........................++..........        .........        ",
"                  ......     .............++++.....+++++.......               ..         ",
"                  ....        .....++++++++++++++++++++.......                           ",
"                 .....         .....+++++++++++++++++........                            ",
"                  ..            ......++++++.++++..........                              ",
"                  .              .......++................                               ",
"                                   .....................                                 ",
"                                    .................                                    ",
"                                        .........                                        ",
"                                            ....                                         ",
"                                            ....                                         ",
"                                             ...                                         ",
"                                              ..                                         ",
"                                                                                         ",
"                                                                                         ",
"                                                                                         ",
"                                                                                         ",
"                                                                                         ",
"                                                                                         ",
"                                                                                         ",
"                                                                                         ",
"                                                                                         ",
"                                                                                         "};



void TetrominoFillXPM(string xmlFile, string xpmFile)
{
  xml_document doc;
  doc.load_file(xmlFile.c_str());

  TetrominoFillXPM(bee_xpm, doc);

  doc.save_file(xmlFile.c_str());
}



int main() {
  // Build 
  string file = "testFile.xml";
  TetrominoFillXPM(file, "This argument currently does not work");
  // TetrominoFillFile(file);  
  
  return 0;
}
