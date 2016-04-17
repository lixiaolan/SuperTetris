#ifndef BOARD
#define BOARD

#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <memory>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <queue>
#include <algorithm>
#include "BlocksAndPieces.hpp"
#include "Utility.hpp"
#include "TetrisFiller.hpp"

using namespace std;

class Board {
public:
  Board() = default;
  Board(unsigned int h, unsigned int w);
  bool dropPiece(shared_ptr<PieceBase> piece, pair<unsigned int, unsigned int> loc);
  void draw();
  bool pieceFits(shared_ptr<PieceBase> piece, pair<unsigned int, unsigned int> loc);
  ~Board() = default;
  unsigned linesKilled = 0;
  
private:
  unsigned int height, width;
  vector<vector <shared_ptr<BlockBase> > > grid;

  void fillEmpty();
  int recCount(unsigned int, unsigned int);
  // void recFill(int, int);
  // void recResetMark(int, int);
  void killLines();
};

#endif
