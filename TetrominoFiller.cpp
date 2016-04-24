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
    set<shared_ptr<BlockBase> > emptyBlocks = getEmptyPieceSurroundings(piece);
    if (emptyBlocks.size() == 0) break;

    shared_ptr<BlockBase> selectedEmptyBlock = nullptr;

    // TODO REMOVE THIS
    vector<int> counts;

    blocks.clear();
    int smallestCount = 100000000;
    int regions = 0;
    for (shared_ptr<BlockBase> emptyBlock : emptyBlocks) {
      int count = recCount(emptyBlock->i, emptyBlock->j);

      // Remove this:
      counts.push_back(count);
      
      if (count % 4 != 0) return false;
      if (count > 0) regions++;
      if (count > 0 && count < smallestCount) {
        smallestCount = count;
        selectedEmptyBlock = emptyBlock;
      }
    }
    
    // for (shared_ptr<BlockBase> emptyBlock : emptyBlocks) {
    //   int count = recCount(emptyBlock->i, emptyBlock->j);
    //   if (count % 4 != 0) return false;
    // }
    
    if (regions < 2) {
      selectedEmptyBlock = getMaxScoredBlock(emptyBlocks);
    }

    // Print some of the selected block information
    // ofstream ofs;
    // ofs.open("temp.txt", std::ios_base::app);
    // ofs << "i: " << selectedEmptyBlock->i << endl;
    // ofs << "j: " << selectedEmptyBlock->j << endl;
    // pair<int, int> analysis = analyzeBlock(selectedEmptyBlock);
    // ofs << "analysis: " << analysis.first << ", " << analysis.first << endl;
    // ofs << "score: " << scoreBlock(selectedEmptyBlock) << endl;
    // vector<shared_ptr<BlockBase> > surroundings = getBlockSurroundings(selectedEmptyBlock);
    // ofs << "surroundings: ";
    // for (auto block : surroundings) {
    //   if (block->isBlank()) {
    //     ofs << "0 ";
    //   }
    //   else {
    //     ofs << "1 ";
    //   }
    // }
    // ofs << endl;
    // ofs << "regions: " << regions << endl;
    // ofs << "empty Blocks: ";
    // for (auto block : emptyBlocks) {
    //   ofs << "(" << block->i << ", " << block->j << ") ";
    // }
    // ofs << endl;
    // ofs << "smallest count: " << smallestCount << endl;
    // ofs << "counts: ";
    // for (int i : counts) {
    //   ofs << i << " ";
    // }
    // ofs << endl;

    // ofs.close();

    
    if (!selectFittingPiece(selectedEmptyBlock->i, selectedEmptyBlock->j)) return false;
  }

  // If we get here, all surrounding pieces have been filed
  return true;
}

int TetrominoFiller::recCount(unsigned int i, unsigned int j) {
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
    shared_ptr<BlockBase> emptyBlockPtr = getEmptyBlockSurrounding(blockPtr);
    if (emptyBlockPtr->isBlank()) return emptyBlockPtr;
  }
  return make_shared<Block>(Block(0, 0, 'X'));
}

// Method searches for blank squares surrounding a piece. The method
// assumes that the piece itself has already been marked.
set<shared_ptr<BlockBase> > TetrominoFiller::getEmptyPieceSurroundings(shared_ptr<PieceBase> piece) {
  set<shared_ptr<BlockBase> > blocksSet;
  for (auto blockPtr : piece->getBlocks()) {
    vector<shared_ptr<BlockBase> > emptyBlocks = getEmptyBlockSurroundings(blockPtr);
    for (auto emptyBlockLoc : emptyBlocks) blocksSet.insert(emptyBlockLoc);
  }
  return blocksSet;
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

int TetrominoFiller::scoreBlock(shared_ptr<BlockBase> block) {
  pair<int, int> analysis = analyzeBlock(block);
  return 9*analysis.first + analysis.second;
}

shared_ptr<BlockBase> TetrominoFiller::getMaxScoredBlock(set<shared_ptr<BlockBase> > blocks) {
  int maxScore = -1;
  shared_ptr<BlockBase> maxBlock = nullptr;
  int temp = 0;
  for (shared_ptr<BlockBase> block : blocks) {
    temp = scoreBlock(block);
    if (temp > maxScore) {
      maxScore = temp;
      maxBlock = block;
    }
  }
  if (maxBlock == nullptr) {
    return make_shared<Block>(Block(0,0,'X'));
  }
  else {
    return maxBlock;
  }
}

pair<int, int> TetrominoFiller::analyzeBlock(shared_ptr<BlockBase> block) {
  // ofstream ofs;
  // ofs.open("debug.txt", std::ios_base::app);
  // ofs << "start analyzeBlock" << endl;

  int regions = 0;
  int neighbors = 0;
  bool inRegion = false;

  shared_ptr<BlockBase> lastBlock;
  shared_ptr<BlockBase> firstBlock = nullptr;

  // ofs << "in analyzeBlock" << endl;
  for (shared_ptr<BlockBase> indexBlock : getBlockSurroundings(block)) {
    if (firstBlock == nullptr) firstBlock = indexBlock;
    lastBlock = indexBlock;
    
    if (indexBlock->isBlank()) {
      if (!inRegion) {
        regions++;
      }
      inRegion = true;
    }
    else {
      neighbors++;
      inRegion = false;
    }
  }

  if (firstBlock->isBlank() && lastBlock->isBlank()) {
    regions--;
  }
  
  pair<int, int> ret;
  ret.first = regions;
  ret.second = neighbors;

  // ofs << "end analyzeBlock" << endl;
  return ret; 
}

vector<shared_ptr<BlockBase> > TetrominoFiller::getBlockSurroundings(shared_ptr<BlockBase> block) {
  // ofstream ofs;
  // ofs.open("debug.txt", std::ios_base::app);
  // ofs << "start getBlockSurroundings" << endl;

  vector<int> iOffset = {0, -1, -1, -1, 0, 1, 1 ,1};
  vector<int> jOffset = {1, 1, 0, -1, -1, -1, 0 ,1};

  vector<shared_ptr<BlockBase> > surroundings;

  for (int index = 0; index < 8; index++) {
  
    int i = block->i;
    int j = block->j;

    i += iOffset[index];
    j += jOffset[index];

    // If we are out of bounds return a non-blank block
    if (i < 0 || i >= (int)(*grid).size()) {
      surroundings.push_back(make_shared<Block>(Block(0, 0, 'X')));
      continue;
    }
    if (j < 0 || j >= (int)(*grid)[0].size()) {
      surroundings.push_back(make_shared<Block>(Block(0, 0, 'X')));
      continue;
    }

    // ofs << "start loop getBlockSurroundings" << endl;
    
    // Otherwise, return a block based on the block in the grid
    if ((*grid)[i][j]->isBlank()) {
      surroundings.push_back(make_shared<BlankBlock>(BlankBlock(i, j)));
    }
    else {
      surroundings.push_back(make_shared<Block>(Block(i, j, 'X')));
    }
  }

  // ofs << "end getBlockSurroundings" << endl;
  return surroundings;
}

// is located inside of the grid.
vector<shared_ptr<BlockBase> > TetrominoFiller::getEmptyBlockSurroundings(shared_ptr<BlockBase> blockPtr) {
  int i = blockPtr->i;
  int j = blockPtr->j;
  vector<shared_ptr<BlockBase> > blocks;
  
  i--;
  if (i >= 0) {
    if ((*grid)[i][j]->isBlank()) {
      blocks.push_back(make_shared<BlankBlock>(BlankBlock(i, j)));
    }
  }
  
  i++;
  j--;
  if (j >= 0) {
    if ((*grid)[i][j]->isBlank()) {
      blocks.push_back(make_shared<BlankBlock>(BlankBlock(i, j)));
    }
  }

  i++;
  j++;
  if (i < (int)(*grid).size()) {
    if ((*grid)[i][j]->isBlank()) {
      blocks.push_back(make_shared<BlankBlock>(BlankBlock(i, j)));
    }
  }

  i--;
  j++;
  if (j < (int)(*grid)[0].size()) {
    if ((*grid)[i][j]->isBlank()) {
      blocks.push_back(make_shared<BlankBlock>(BlankBlock(i, j)));
    }
  }

  return blocks;
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
