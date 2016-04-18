#ifndef TETRIS_FILLER
#define TETRIS_FILLER

#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <memory>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <queue>
#include <algorithm>
#include "BlocksAndPieces.hpp"
#include "Utility.hpp"
#include <fstream>
#include <algorithm>

using namespace std;

class TetrominoFiller {
public:
  TetrominoFiller(vector<vector<shared_ptr<BlockBase > > > * grid);
  bool fill(unsigned int i, unsigned int j);
  stack<shared_ptr<PieceBase> > getSolutionStack();
private:
  vector<vector<shared_ptr<BlockBase > > > * grid;
  stack<shared_ptr<PieceBase> > pieces;
  set<shared_ptr<BlockBase> > blocks;
  int recCount(unsigned int i, unsigned int j);
  bool selectFittingPiece(unsigned int i, unsigned int j);
  bool surroundPiece(shared_ptr<PieceBase> piece);
  void addPiece(shared_ptr<PieceBase> piece);
  void removeUpToAndIncluding(shared_ptr<PieceBase> piece);  
  // Method searches for unmarked squares surrounding a piece. The
  // method assumes that the piece itself has already been marked. 
  shared_ptr<BlockBase> getEmptyPieceSurrounding(shared_ptr<PieceBase> piece);
  // Finds an blank unmarked bock surrounding the input block. Assumes
  // the block is located inside of the grid.
  shared_ptr<BlockBase> getEmptyBlockSurrounding(shared_ptr<BlockBase> blockPtr);
  bool pieceFits(shared_ptr<PieceBase> piece);
  void printGrid();
};

#endif
