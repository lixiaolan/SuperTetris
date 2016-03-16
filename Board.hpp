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
  Board(int h, int w);
  bool dropPiece(shared_ptr<PieceBase> piece, pair<int, int> loc);
  void draw();
  bool pieceFits(shared_ptr<PieceBase> piece, pair<int, int> loc);
  ~Board() = default;
  unsigned linesKilled = 0;
  
private:
  int height, width;
  vector<vector <shared_ptr<BlockBase> > > grid;

  void fillEmpty();
  int recCount(int, int);
  void recFill(int, int);
  void recResetMark(int, int);
  void killLines();
};

#endif
