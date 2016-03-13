#include "Board.hpp"

Board::Board(int h, int w) : height(h), width(w) {
  //build the top row:
  vector<shared_ptr<BlockBase> > toprow;
  for (int i = 0; i < width+2; i++) {
    toprow.push_back(make_shared<TopEdgeBlock>(TopEdgeBlock(i, 0)));
  }
  grid.push_back(toprow);
  //build the h middle rows:

  for (int j = 1; j < height+1; j++) {
    vector<shared_ptr<BlockBase> > midrow;
    for (int i = 0; i < width+2; i++) {
      if ((i == 0)||(i==w+1)) {
        midrow.push_back(make_shared<LRBEdgeBlock>(LRBEdgeBlock(i, j)));	
      } else {
        midrow.push_back(make_shared<BlankBlock>(BlankBlock(i, j)));	
      }
    }
    grid.push_back(midrow);
  }
  // Build the bottom rwo:
  vector<shared_ptr<BlockBase> > botrow;
  for (int i = 0; i < width+2; i++) {
    botrow.push_back(make_shared<LRBEdgeBlock>(LRBEdgeBlock(i, height+1)));
  }
  grid.push_back(botrow);
}


void Board::draw() {
  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[0].size(); j++) {
      mvaddch(i, 2*j, grid[i][j]->draw() );
      mvaddch(i, 2*j+1, ' ' );
    }
  }         
  refresh();
}

void Board::killLines() {
  int slow = grid.size()-2;
  int fast = grid.size()-2;
  bool killLine[grid.size()]; 
  //iterate the slow and fast
  bool has;
  for (int i = 0; i < grid.size(); i++) {
    has = false;
    for (int j = 0; j < grid[0].size(); j++) {
      if ((i==0)||(i==grid.size()-1)) has = true;
	has = (has||grid[i][j]->isBlank());
    }
    killLine[i] = !has;
  }

  //COMMENT OUT THE FIRE SWEEPS TO GET REGULAR TETRIS.
  
  // // Fire sweep up
  // for (int i = 1; i < grid.size(); i++) {
  //   has = false;
  //   for (int j = 0; j < grid[0].size(); j++) {
  //     has = (has||grid[i][j]->isFire());
  //   }
  //   if ((has)&&(killLine[i-1])) {
  //     killLine[i] = true;
  //   }
  // }

  // // Fire sweep down
  // for (int i = grid.size()-2; i >= 0; i--) {
  //   has = false;
  //   for (int j = 0; j < grid[0].size(); j++) {
  //     has = (has||grid[i][j]->isFire());
  //   }
  //   if ((has)&&(killLine[i+1])) {
  //     killLine[i] = true;
  //   }
  // }

  // Now kill all the lines
  while (fast > 0) {
    if (killLine[fast]) {
      fast--;
    } 
    // else write fast to slow and increment both
    else {
      grid[slow] = grid[fast];
      slow--;
      fast--;
    }
  }
 
  while (slow > 0) {
    vector<shared_ptr<BlockBase> > midrow;
    for (int i = 0; i < width+2; i++) {
      if ((i == 0)||(i==width+1)) {
	midrow.push_back(make_shared<LRBEdgeBlock>(LRBEdgeBlock(0, 0)));	
      } else {
	midrow.push_back(make_shared<BlankBlock>(BlankBlock(0, 0)));	
      }
    }
    grid[slow] = midrow;
    slow--;
  }
  // After the loop write everything from slow up to 1 with blank rows;
}

bool Board::pieceFits(shared_ptr<PieceBase> piece, pair<int, int> loc) {
  vector<vector<bool> > space;
  for (int i = loc.first; i < loc.first + 4; i++) {
    vector<bool> col;
    for (int j = loc.second; j < loc.second + 4; j++) {
      if ((i < grid.size())&&(j < grid[0].size())) {
	col.push_back(!(grid[i][j]->isBlank()));
      } else {
	col.push_back(true);
      }
    }
    space.push_back(col);
  }
  return piece->fitsIn(space);
}

bool Board::dropPiece(shared_ptr<PieceBase> piece, pair<int, int> loc) {
  if (pieceFits(piece, loc)) {
    while(pieceFits(piece, loc)) {
      loc.first = loc.first + 1;
    }
    loc.first = loc.first - 1;
    for (auto b : piece->getBlocks()) {
      grid[loc.first + b->i][loc.second + b->j] = b;
    }
    fillEmpty();
    killLines();
    return true;
  }
  else {
    return false;
  }
}

void Board::fillEmpty() {
  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[0].size(); j++) {
      // If blank, do a recursive count. Mark checked blocks
      if (grid[i][j]->isBlank()) {
	if (!(grid[i][j]->mark)) {
	  // if recursive count returns 4, do a recursive fill with
	  // "fire" blocks

	  int c = recCount(i,j);
          if ((c % 4) == 0 && c <= 12 ) {
            TetrisFiller tetrisFiller = TetrisFiller(&grid);
            bool testBool = tetrisFiller.fill(i, j);
            if (!testBool) {
              recCount(i,j);
            }            
          }
	}
      }     
    }
  }

  // Unmark all blank in a second double loop here.
  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[0].size(); j++) {
      grid[i][j]->mark = false;   
    }
  }
  return;
}

int Board::recCount(int i, int j) {
  if (!(grid[i][j]->isBlank() )) { return false; }
  if (grid[i][j]->mark) {return false; }
  grid[i][j]->mark = true;

  int u;
  int d;
  int l;
  int r;
  if (i-1 >= 0) {
    u = recCount(i-1, j);
  }
  if (i+1 < grid.size()) {
    d = recCount(i+1, j);
  }
  if (j-1 >= 0) {
    l = recCount(i, j-1);
  }
  if (j+1 < grid[0].size()) {
    r = recCount(i, j+1);
  }

  return 1+u+d+l+r;
}

void Board::recResetMark(int i, int j) {
  if (!(grid[i][j]->isBlank() )) { return; }
  if (!grid[i][j]->mark) {return; }
  grid[i][j]->mark = false;

  if (i-1 >= 0) {
    recResetMark(i-1, j);
  }
  if (i+1 < grid.size()) {
    recResetMark(i+1, j);
  }
  if (j-1 >= 0) {
    recResetMark(i, j-1);
  }
  if (j+1 < grid[0].size()) {
    recResetMark(i, j+1);
  }
  return;
}

void Board::recFill(int i,int j) {
  if (!(grid[i][j]->isBlank())) { return; }
  grid[i][j] = make_shared<FireBlock>( FireBlock(i,j) );
  if (i-1 >= 0) {
    recFill(i-1,j);
  }
  if (i+1 < grid.size()) {
    recFill(i+1,j);
  }
  if (j-1 >= 0) {
    recFill(i,j-1);
  }
  if (j+1 < grid[0].size()) {
    recFill(i,j+1);
  }
  return;
}
