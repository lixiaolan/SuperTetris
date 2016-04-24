#include "PolyominoFiller.hpp"

virtual bool PolyominoFiller::fill(unsigned int i, unsigned int j) {
  return selectFittingPiece(i, j);
}

stack<shared_ptr<PieceBase> > PolyominoFiller::getSolutionStack() {
  return pieces;
}

// Recursive method which attempts to 
bool PolyominoFiller::selectFittingPiece(unsigned int i, unsigned int j)
{
  // Check the starting location first
  if (!validInputLocation(i, j)) return false;

  // Try all pieces
  for (shared_ptr<PieceBase> piece : getAnchoredPieces(i, j) ) {
    
    // Check if piece actually fits
    if (!pieceFits(piece)) continue;
      
    // Make the new piece
    addPiece(piece);

    // Try to surround piece. If we succeed, return true.
    if (surroundPiece(piece)) return true;

    // If the piece could not be surrounded, remove it
    removeUpToAndIncluding(piece);
  }

  // If no piece fits, return false
  return false;
}

// Method to validate an input location. Note: I am not sure if I need
// this so it defaults to returning true always.
virtual bool PolyominoFiller::validInputLocation(unsigned int i, unsigned int j) {
  return true;
}

virtual vector<shared_ptr<PieceBase> > getAnchoredPieces(unsigned int i, unsigned int j) = 0;

// Recursive method which attempts to surround an input piece with other pieces
bool PolyominoFiller::surroundPiece(shared_ptr<PieceBase> piece) {

  // Keep iterating until all surrounding squares are filled
  while(1) {

    // Get the next empty block to fill
    shared_ptr<BlockBase> selectedEmptyBlock = selectNextEmptyBlock(piece);

    // If the next empty block is not actually empty, the input piece
    // is fully surrounded so we break from the loop.
    if (!selectedEmptyBlock->isBlank()) break;

    // Fill the empty block with a new piece
    if (!selectFittingPiece(selectedEmptyBlock->i, selectedEmptyBlock->j)) return false;
  }

  // If we get here, all surrounding pieces have been filed
  return true;
}

virtual void PolyominoFiller::addPiece(shared_ptr<PieceBase> piece) {
  // Add to stack
  pieces.push(piece);
}

void PolyominoFiller::removeUpToAndIncluding(shared_ptr<PieceBase> piece) {
  while(pieces.size() > 0) {
    shared_ptr<PieceBase> top = pieces.top();
    pieces.pop();
    removePiece(piece);
    if (top == piece) break;
  }
}

virtual void PolyominoFiller::removePiece(shared_ptr<PieceBase> piece) = 0;

virtual bool PolyominoFiller::pieceFits(shared_ptr<PieceBase> piece) = 0;

