#ifndef UTILITY
#define UTILITY

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

using namespace std;

// rotate by i*pi/2 radiants ccw
void rotatePiece(shared_ptr<PieceBase> piece, unsigned i);
// Translate piece by offset vector
void translatePiece(shared_ptr<PieceBase> piece, int iOffset, int jOffset);
// Function to enumerate all ppossible pieces anchored at 0,0. The
// index should be less than 76.
shared_ptr<PieceBase> getAnchoredPiece(unsigned index);

// Generate a random piece 
class RandomPieceFactory {
public:
  RandomPieceFactory() = default;
  shared_ptr<PieceBase> getPiece();
};

class RandomPieceFactory2 {
public:
  RandomPieceFactory2() = default;
  shared_ptr<PieceBase> getPiece();
};

#endif
