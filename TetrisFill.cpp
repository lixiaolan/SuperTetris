vector<vector<shared_ptr<BlockBase > > > buildGrid(int rows, int cols, string gridString)
{
  stringstream ss(gridString);
  int count = 0;
  vector<vector<shared_ptr<BlockBase>>> grid;
  vector<shared_ptr<BlockBase>> gridRow;
  string cell;
  while (ss >> cell) {
    if (cell == "0") {
      gridRow.push(make_shared<BlockBase>(BlankBlock(count / cols, count % cols));
    }
    else if (cell = "1") {
      gridRow.push(make_shared<BlockBase>(Block(count / cols, count % cols, '1'));
    }
    else {
      // TODO: handle the error here
    }
    count++;
    if (count % cols == 0) {
      grid.push(gridRow);
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

// Function to take a tetris fill puzzle and create a solution
string TetrisFill(string input)
{
  // De-searilize string into xml object
  xml_document doc;
  doc.read(input);
  xml_node problem = doc.child("tetrisFill").child("problem");
  
  // Read the problem and build the grid and extract start point
  xml_node gridNode = problem.child("grid");
  int gridRows = GetAttributeAsInt(gridNode, "row");
  int gridCols = GetAttributeAsInt(gridNode, "col");
  string gridString = string(gridNode.text().get());
  xml_node start = problem.child("start");
  int startRow = GetAttributeAsInt(start, "row");
  int startCol = GetAttributeAsInt(start, "col");

  vector<vector<shared_ptr<BlockBase > > > grid = buildGrid(gridRows, gridCols, gridString);
  // Pass the grid and start point to the tetris solver alg

  TetrisFiller filler = TetrisFille(&grid);
  filler.fill(startRow, startCol);

  // Get the solution stack and write to xml object
  stack<shared_ptr<PieceBase> > solutionStack = filler.getSolutionStack();
  

  
  // Searialize xml object back into string and return
}

int main() {
  // Build 

  Game g;
  g.run();
  return 0;
}
