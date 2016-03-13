#include "TetrisFiller.hpp"

TetrisFiller::TetrisFiller(vector<vector<shared_ptr<BlockBase > > > * grid) {this->grid = grid; };

bool TetrisFiller::fill(int i, int j) {
  if ((i > 0) && (i < (*grid).size()) && (j > 0) && (j < (*grid)[0].size())) {
    return selectFittingPiece(i, j);
  }
  else {
    return false;
  }
}
  
bool TetrisFiller::selectFittingPiece(int i, int j)
{
  if (!((*grid)[i][j]->isBlank() )) { return false; }

  // Try all pieces
  for (unsigned index = 0; index < 76; index++) {
    shared_ptr<PieceBase> piece = getAnchoredPiece(index);
    translatePiece(piece, i, j);

    // Check if piece actually fits
    if (pieceFits(piece)) {
      // cout << "found fitting piece: #" << index << " at (" << i << " ," << j << ")";
      
      // Make the new piece
      addPiece(piece);

      // Try to surround piece
      if (surroundPiece(piece)) {

        // If we surrounded piece the succesfully, return true
        return true;
      }

      // If the piece could not be surrounded, remove it
      removeUpToAndIncluding(piece);
    }
  }

  // If acceptable piece fit, return false
  return false;
}

bool TetrisFiller::surroundPiece(shared_ptr<PieceBase> piece) {
  int i;
  int j;
  
  // Keep iterating until all surrounding squares are filled
  while(1) {
    if (getEmptyPieceSurrounding(piece, i, j)) {
      // cout << "got empty piece surrounding block at (" << i << " ," << j << ")";
      if (!selectFittingPiece(i, j)) return false;
    }
    else {
      break;
    }
  }

  // If we get here, all surrounding pieces have been filed
  return true;
}

void TetrisFiller::addPiece(shared_ptr<PieceBase> piece) {
  // Add to stack
  pieces.push(piece);
  // Add to grid
  for (auto block : piece->getBlocks()) {
    (*grid)[block->i][block->j] = block;
  }
}

void TetrisFiller::removeUpToAndIncluding(shared_ptr<PieceBase> piece) {
  while(pieces.size() > 0) {
    shared_ptr<PieceBase> top = pieces.top();
    pieces.pop();
    for (auto block : top->getBlocks()) {
      (*grid)[block->i][block->j] = make_shared<BlankBlock>(BlankBlock(block->i, block->j));
    }
    if (top == piece) break;
  }
}

// Method searches for unmarked squares surrounding a piece. The
// method assumes that the piece itself has already been marked. 
bool TetrisFiller::getEmptyPieceSurrounding(shared_ptr<PieceBase> piece, int &i, int &j) {
  for (auto blockPtr : piece->getBlocks()) {
    if (getEmptyBlockSurrounding(blockPtr, i, j)) return true;
  }
  return false;
}

// Finds an blank unmarked bock surrounding the input block. Assumes
// the block is located inside of the grid.
bool TetrisFiller::getEmptyBlockSurrounding(shared_ptr<BlockBase> blockPtr, int &i, int &j) {
  i = blockPtr->i;
  j = blockPtr->j;

  i--;
  if (i > 0) {
    if ((*grid)[i][j]->isBlank())
      return true;
  }
  
  i++;
  j--;
  if (j > 0) {
    if ((*grid)[i][j]->isBlank())
      return true;
  }

  i++;
  j++;
  if (i < (*grid).size()) {
    if ((*grid)[i][j]->isBlank())
      return true;
  }

  i--;
  j++;
  if (j < (*grid)[0].size()) {
    if ((*grid)[i][j]->isBlank())
      return true;
  }

  return false;
}

bool TetrisFiller::pieceFits(shared_ptr<PieceBase> piece) {
  for (auto block : piece->getBlocks()) {
    // Verify that each block is inside the grid
    if (block->i < 0) return false;
    if (block->j < 0) return false;
    if (block->i >= (*grid).size()) return false;
    if (block->j >= (*grid)[0].size()) return false;

    // Verify that each block is blank
    if (!((*grid)[block->i][block->j]->isBlank())) return false;
  }
  return true;
}
