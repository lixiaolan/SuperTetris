#include "TetrominoFiller.hpp"

TetrominoFiller::TetrominoFiller(vector<vector<shared_ptr<BlockBase > > > * grid) {this->grid = grid; };

bool TetrominoFiller::fill(unsigned int i, unsigned int j) {

  // Seed the random number generator
  srand(time(0));
  
  if ((i >= 0) && (i < (*grid).size()) && (j >= 0) && (j < (*grid)[0].size())) {
    return selectFittingPiece(i, j);
  }
  else {
    return false;
  }
}

stack<shared_ptr<PieceBase> > TetrominoFiller::getSolutionStack() {
  return pieces;
}

bool TetrominoFiller::selectFittingPiece(unsigned int i, unsigned int j)
{
  if (!((*grid)[i][j]->isBlank() )) { return false; }

  vector<unsigned> randomArray;
  for (unsigned index = 0; index < 76; index++)
    randomArray.push_back(index);

  random_shuffle(randomArray.begin(), randomArray.end());
  
  // Try all pieces
  for (unsigned index = 0; index < 76; index++) {
    
    shared_ptr<PieceBase> piece = getAnchoredPiece(randomArray[index]);
    piece->translate(i, j);

    // Check if piece actually fits
    if (pieceFits(piece)) {
      
      // Make the new piece
      addPiece(piece);

      //print for debugging
      // printGrid();

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

bool TetrominoFiller::surroundPiece(shared_ptr<PieceBase> piece) {

  // Keep iterating until all surrounding squares are filled
  while(1) {
    shared_ptr<BlockBase> blockPtr = getEmptyPieceSurrounding(piece);
    if (blockPtr->isBlank()) {

      blocks.clear();
      
      int count = recCount(blockPtr->i, blockPtr->j);

      // ofstream ofs;
      // ofs.open("temp.txt", std::ios_base::app);

      // ofs << "i: " << blockPtr->i << endl;
      // ofs << "j: " << blockPtr->j << endl;
      // ofs << "count: " << count << endl;
      // ofs.close();
      
      if (count % 4 != 0) return false;
      
      if (!selectFittingPiece(blockPtr->i, blockPtr->j)) return false;
    }
    else {
      break;
    }
  }

  // If we get here, all surrounding pieces have been filed
  return true;
}

int TetrominoFiller::recCount(unsigned int i, unsigned int j) {
  if (!((*grid)[i][j]->isBlank() )) return 0;
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

void TetrominoFiller::addPiece(shared_ptr<PieceBase> piece) {
  // Add to stack
  pieces.push(piece);
  // Add to grid
  for (auto block : piece->getBlocks()) {
    (*grid)[block->i][block->j] = block;
  }
}

void TetrominoFiller::removeUpToAndIncluding(shared_ptr<PieceBase> piece) {
  while(pieces.size() > 0) {
    shared_ptr<PieceBase> top = pieces.top();
    pieces.pop();
    for (auto block : top->getBlocks()) {
      (*grid)[block->i][block->j] = make_shared<BlankBlock>(BlankBlock(block->i, block->j));
    }
    if (top == piece) break;
  }
}

// Method searches for blank squares surrounding a piece. The method
// assumes that the piece itself has already been marked.
shared_ptr<BlockBase> TetrominoFiller::getEmptyPieceSurrounding(shared_ptr<PieceBase> piece) {
  for (auto blockPtr : piece->getBlocks()) {
    shared_ptr<BlockBase> emptryBlockPtr = getEmptyBlockSurrounding(blockPtr);
    if (emptryBlockPtr->isBlank()) return emptryBlockPtr;
  }
  return make_shared<Block>(Block(0, 0, 'X'));
}

// Finds a blank bock surrounding the input block. Assumes the block
// is located inside of the grid.
shared_ptr<BlockBase> TetrominoFiller::getEmptyBlockSurrounding(shared_ptr<BlockBase> blockPtr) {
  int i = blockPtr->i;
  int j = blockPtr->j;

  i--;
  if (i >= 0) {
    if ((*grid)[i][j]->isBlank()) {
      return make_shared<BlankBlock>(BlankBlock(i, j));
    }
  }
  
  i++;
  j--;
  if (j >= 0) {
    if ((*grid)[i][j]->isBlank()) {
      return make_shared<BlankBlock>(BlankBlock(i, j));
    }
  }

  i++;
  j++;
  if (i < (int)(*grid).size()) {
    if ((*grid)[i][j]->isBlank()) {
      return make_shared<BlankBlock>(BlankBlock(i, j));
    }
  }

  i--;
  j++;
  if (j < (int)(*grid)[0].size()) {
    if ((*grid)[i][j]->isBlank()) {
      return make_shared<BlankBlock>(BlankBlock(i, j));
    }
  }

  return make_shared<Block>(Block(0, 0, 'X'));
}

// Finds a blank bock surrounding the input block. Assumes the block
// is located inside of the grid.
vector<shared_ptr<BlockBase> > TetrominoFiller::getEmptyBlocksSurrounding(shared_ptr<BlockBase> blockPtr) {
  int i = blockPtr->i;
  int j = blockPtr->j;
  vector<shared_ptr<BlockBase> > surroundingBlankBlocks;
  
  i--;
  if (i >= 0) {
    if ((*grid)[i][j]->isBlank()) {
      surroundingBlankBlocks.push_back((*grid)[i][j]);
    }
  }
  
  i++;
  j--;
  if (j >= 0) {
    if ((*grid)[i][j]->isBlank()) {
      surroundingBlankBlocks.push_back((*grid)[i][j]);
    }
  }

  i++;
  j++;
  if (i < (int)(*grid).size()) {
    if ((*grid)[i][j]->isBlank()) {
      surroundingBlankBlocks.push_back((*grid)[i][j]);
    }
  }

  i--;
  j++;
  if (j < (int)(*grid)[0].size()) {
    if ((*grid)[i][j]->isBlank()) {
      surroundingBlankBlocks.push_back((*grid)[i][j]);
    }
  }

  return surroundingBlankBlocks;
}

bool TetrominoFiller::pieceFits(shared_ptr<PieceBase> piece) {
  for (auto block : piece->getBlocks()) {
    // Verify that each block is inside the grid
    if (block->i < 0) return false;
    if (block->j < 0) return false;
    if (block->i >= (int)(*grid).size()) return false;
    if (block->j >= (int)(*grid)[0].size()) return false;

    // Verify that each block is blank
    if (!((*grid)[block->i][block->j]->isBlank())) return false;
  }
  return true;
}

void TetrominoFiller::printGrid() {
  ofstream ofs;
  ofs.open("temp.txt", std::ios_base::app);
  for (unsigned int i = 0; i < (*grid).size(); i++) {
    for (unsigned int j = 0; j < (*grid)[0].size(); j++) {
      ofs << (*grid)[i][j]->draw() << " ";
    }
    ofs << endl;
  }
}
