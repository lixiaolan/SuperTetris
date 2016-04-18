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
  xml_node solution = doc.child("tetrisFill").append_child("solution");
  stack<shared_ptr<PieceBase> > solutionStack = filler.getSolutionStack();
  shared_ptr<PieceBase> piece;
  while (!solutionStack.empty()) {
    piece = solutionStack.top();
    xml_node pieceNode = solution.append_child("piece");
    pieceNode.append_attribute("type") = IntToString(piece->Id()).c_str();
    pieceNode.append_attribute("row") = IntToString(piece->i).c_str();
    pieceNode.append_attribute("col") = IntToString(piece->j).c_str();
    solutionStack.pop();
  }
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

int main() {
  // Build 
  string file = "testFile.xml";
  TetrominoFillFile(file);  
  
  return 0;
}
