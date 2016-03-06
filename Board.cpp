#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <queue>
#include <algorithm>

using namespace std;

class BlockBase {
public:
  bool mark = false;
  int i;
  int j;
  BlockBase() = default;
  BlockBase(int a, int b) : i(a), j(b) {};
  virtual char draw() = 0;
  virtual bool isEdge() {return false;};
  virtual bool isBlank() {return false;};
  virtual bool isFire() {return false;};
};

class EdgeBlock : public BlockBase {
public:
  EdgeBlock(int a, int b) : BlockBase(a,b) {};
  bool isEdge() {return true; };
};

class LRBEdgeBlock : public EdgeBlock {
public:
  LRBEdgeBlock(int a, int b) : EdgeBlock(a,b) {};
  char draw() { return 'H'; };
};

class TopEdgeBlock : public EdgeBlock {
public:
  TopEdgeBlock(int a, int b) : EdgeBlock(a,b) {};
  char draw() { return ' '; };
};

class BlankBlock : public BlockBase {
public:
  BlankBlock(int a, int b) : BlockBase(a, b) {};
  char draw() { return ' '; };
  bool isBlank() {return true; };
};

class Block : public BlockBase {
protected:
  char image;
public:
  Block(int a, int b, char s) : BlockBase(a,b), image(s) {};
  char draw() {return image; };
};

class FireBlock : public Block {
public:
  FireBlock(int a, int b) : Block(a,b,'X') {};
  virtual bool isFire() {return true;};
};

//PIECES:

class PieceBase {
protected:
  vector<shared_ptr<Block> > blocks;
  // positions of upper left corner
public:
  PieceBase() = default;
  bool fitsIn(vector<vector< bool> > matrix) {
    // Expects array where true is open and false is filled    
    for (auto pb : blocks) {
      if (matrix[pb->i][pb->j]) return false;
    }
    return true;
  };
  vector<shared_ptr<Block> > getBlocks() {return blocks; };
  void draw(pair<int, int> loc) {
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
	for (auto b : blocks) {
	  if ((b->i == i)&&(b->j == j)) {
	    mvaddch(i+loc.first, 2*(j+loc.second), b->draw());
	    mvaddch(i+loc.first, 2*(j+loc.second)+1, ' ');
	    break;
	  } 
	}
      }
    }
    refresh();
  };
  ~PieceBase() = default;
};

class Ell0 : public PieceBase {
public:
  Ell0() {
    blocks.push_back(make_shared<Block>(Block(0, 0, '0') ) ); // 0
    blocks.push_back(make_shared<Block>(Block(1, 0, '0') ) ); // 0
    blocks.push_back(make_shared<Block>(Block(2, 0, '0') ) ); // 0 0
    blocks.push_back(make_shared<Block>(Block(2, 1, '0') ) );
  }
};

class Ell1 : public PieceBase {
public:
  Ell1() {
    blocks.push_back(make_shared<Block>(Block(1, 0, '0') ) ); //     0
    blocks.push_back(make_shared<Block>(Block(1, 1, '0') ) ); // 0 0 0
    blocks.push_back(make_shared<Block>(Block(1, 2, '0') ) ); // 
    blocks.push_back(make_shared<Block>(Block(0, 2, '0') ) );
  }
};

class Ell2 : public PieceBase {
public:
  Ell2() {
    blocks.push_back(make_shared<Block>(Block(0, 0, '0') ) ); // 0 0
    blocks.push_back(make_shared<Block>(Block(0, 1, '0') ) ); //   0
    blocks.push_back(make_shared<Block>(Block(1, 1, '0') ) ); //   0
    blocks.push_back(make_shared<Block>(Block(2, 1, '0') ) );
  }
};

class Ell3 : public PieceBase {
public:
  Ell3() {
    blocks.push_back(make_shared<Block>(Block(1, 0, '0') ) ); // 0 0 0
    blocks.push_back(make_shared<Block>(Block(0, 0, '0') ) ); // 0
    blocks.push_back(make_shared<Block>(Block(0, 1, '0') ) ); 
    blocks.push_back(make_shared<Block>(Block(0, 2, '0') ) );
  }
};

class EllRev0 : public PieceBase {
public:
  EllRev0() {
    blocks.push_back(make_shared<Block>(Block(0, 1, '0') ) ); //   0
    blocks.push_back(make_shared<Block>(Block(1, 1, '0') ) ); //   0
    blocks.push_back(make_shared<Block>(Block(2, 1, '0') ) ); // 0 0
    blocks.push_back(make_shared<Block>(Block(2, 0, '0') ) );
  }
};

class EllRev1 : public PieceBase {
public:
  EllRev1() {
    blocks.push_back(make_shared<Block>(Block(0, 0, '0') ) ); // 0 0 0
    blocks.push_back(make_shared<Block>(Block(0, 1, '0') ) ); //     0
    blocks.push_back(make_shared<Block>(Block(0, 2, '0') ) ); 
    blocks.push_back(make_shared<Block>(Block(1, 2, '0') ) );
  }
};

class EllRev2 : public PieceBase {
public:
  EllRev2() {
    blocks.push_back(make_shared<Block>(Block(1, 0, '0') ) ); // 0 0
    blocks.push_back(make_shared<Block>(Block(0, 0, '0') ) ); // 0
    blocks.push_back(make_shared<Block>(Block(0, 1, '0') ) ); // 0
    blocks.push_back(make_shared<Block>(Block(0, 2, '0') ) );
  }
};

class EllRev3 : public PieceBase {
public:
  EllRev3() {
    blocks.push_back(make_shared<Block>(Block(0, 0, '0') ) ); // 0
    blocks.push_back(make_shared<Block>(Block(1, 0, '0') ) ); // 0 0 0
    blocks.push_back(make_shared<Block>(Block(1, 1, '0') ) ); 
    blocks.push_back(make_shared<Block>(Block(1, 2, '0') ) );
  }
};

class Tee0 : public PieceBase {
public:
  Tee0() {
    blocks.push_back(make_shared<Block>(Block(0, 0, '0') ) ); // 0 0 0
    blocks.push_back(make_shared<Block>(Block(0, 1, '0') ) ); //   0
    blocks.push_back(make_shared<Block>(Block(0, 2, '0') ) ); 
    blocks.push_back(make_shared<Block>(Block(1, 1, '0') ) );
  }
};

class Tee1 : public PieceBase {
public:
  Tee1() {
    blocks.push_back(make_shared<Block>(Block(0, 0, '0') ) ); // 0
    blocks.push_back(make_shared<Block>(Block(1, 0, '0') ) ); // 0 0
    blocks.push_back(make_shared<Block>(Block(2, 0, '0') ) ); // 0
    blocks.push_back(make_shared<Block>(Block(1, 1, '0') ) );
  }
};

class Tee2 : public PieceBase {
public:
  Tee2() {
    blocks.push_back(make_shared<Block>(Block(0, 1, '0') ) ); //   0
    blocks.push_back(make_shared<Block>(Block(1, 0, '0') ) ); // 0 0 0
    blocks.push_back(make_shared<Block>(Block(1, 1, '0') ) );
    blocks.push_back(make_shared<Block>(Block(1, 2, '0') ) );
  }
};

class Tee3 : public PieceBase {
public:
  Tee3() {
    blocks.push_back(make_shared<Block>(Block(1, 0, '0') ) ); //   0
    blocks.push_back(make_shared<Block>(Block(0, 1, '0') ) ); // 0 0
    blocks.push_back(make_shared<Block>(Block(1, 1, '0') ) ); //   0
    blocks.push_back(make_shared<Block>(Block(2, 1, '0') ) );
  }
};

class Zee0 : public PieceBase {
public:
  Zee0() {
    blocks.push_back(make_shared<Block>(Block(0, 0, '0') ) ); // 0 0
    blocks.push_back(make_shared<Block>(Block(0, 1, '0') ) ); //   0 0
    blocks.push_back(make_shared<Block>(Block(1, 1, '0') ) ); //
    blocks.push_back(make_shared<Block>(Block(1, 2, '0') ) );
  }
};

class Zee1 : public PieceBase {
public:
  Zee1() {
    blocks.push_back(make_shared<Block>(Block(0, 1, '0') ) ); //   0
    blocks.push_back(make_shared<Block>(Block(1, 1, '0') ) ); // 0 0
    blocks.push_back(make_shared<Block>(Block(1, 0, '0') ) ); // 0
    blocks.push_back(make_shared<Block>(Block(2, 0, '0') ) );
  }
};

class ZeeRev0 : public PieceBase {
public:
  ZeeRev0() {
    blocks.push_back(make_shared<Block>(Block(1, 0, '0') ) ); //   0 0
    blocks.push_back(make_shared<Block>(Block(1, 1, '0') ) ); // 0 0
    blocks.push_back(make_shared<Block>(Block(0, 1, '0') ) ); //
    blocks.push_back(make_shared<Block>(Block(0, 2, '0') ) );
  }
};

class ZeeRev1 : public PieceBase {
public:
  ZeeRev1() {
    blocks.push_back(make_shared<Block>(Block(0, 0, '0') ) ); // 0
    blocks.push_back(make_shared<Block>(Block(0, 1, '0') ) ); // 0 0
    blocks.push_back(make_shared<Block>(Block(1, 1, '0') ) ); //   0
    blocks.push_back(make_shared<Block>(Block(1, 2, '0') ) );
  }
};

class Dash0 : public PieceBase {
public:
  Dash0() {
    blocks.push_back(make_shared<Block>(Block(0, 0, '0') ) ); // 0 0 0 0
    blocks.push_back(make_shared<Block>(Block(0, 1, '0') ) ); // 
    blocks.push_back(make_shared<Block>(Block(0, 2, '0') ) ); // 
    blocks.push_back(make_shared<Block>(Block(0, 3, '0') ) );
  }
};

class Dash1 : public PieceBase {
public:
  Dash1() {
    blocks.push_back(make_shared<Block>(Block(0, 0, '0') ) ); // 0
    blocks.push_back(make_shared<Block>(Block(1, 0, '0') ) ); // 0
    blocks.push_back(make_shared<Block>(Block(2, 0, '0') ) ); // 0
    blocks.push_back(make_shared<Block>(Block(3, 0, '0') ) ); // 0
  }
};

class Box : public PieceBase {
public:
  Box() {
    blocks.push_back(make_shared<Block>(Block(0, 0, '0') ) ); // 0 0
    blocks.push_back(make_shared<Block>(Block(0, 1, '0') ) ); // 0 0
    blocks.push_back(make_shared<Block>(Block(1, 0, '0') ) ); // 
    blocks.push_back(make_shared<Block>(Block(1, 1, '0') ) ); // 
  }
};

class RandomPieceFactory {
public:
  RandomPieceFactory() = default;
  shared_ptr<PieceBase> getPiece() {
    int index = rand() % 20;
    switch (index%19) {
    case(0):
      return make_shared<Ell0>(Ell0());
    case(1):
      return make_shared<Ell1>(Ell1());
    case(2):
      return make_shared<Ell2>(Ell2());
    case(3):
      return make_shared<Ell3>(Ell3());
    case(4):
      return make_shared<EllRev0>(EllRev0());
    case(5):
      return make_shared<EllRev1>(EllRev1());
    case(6):
      return make_shared<EllRev2>(EllRev2());
    case(7):
      return make_shared<EllRev3>(EllRev3());
    case(8):
      return make_shared<Tee0>(Tee0());
    case(9):
      return make_shared<Tee1>(Tee1());
    case(10):
      return make_shared<Tee2>(Tee2());
    case(11):
      return make_shared<Tee3>(Tee3());
    case(12):
      return make_shared<Zee0>(Zee0());
    case(13):
      return make_shared<Zee1>(Zee1());
    case(14):
      return make_shared<ZeeRev0>(ZeeRev0());
    case(15):
      return make_shared<ZeeRev1>(ZeeRev1());
    case(16):
      return make_shared<Dash0>(Dash0());
    case(17):
      return make_shared<Dash1>(Dash1());
    case(18):
      return make_shared<Box>(Box());
    }
  };
};

class RandomPieceFactory2 {
public:
  RandomPieceFactory2() = default;
  shared_ptr<PieceBase> getPiece() {
    int index1 = rand() % 7;
    int index2 = rand();
    switch (index1 % 19) {
    case(0):
      switch(index2 % 4) {
      case(0):
	return make_shared<Ell0>(Ell0());
      case(1):
	return make_shared<Ell1>(Ell1());
      case(2):
	return make_shared<Ell2>(Ell2());
      case(3):
	return make_shared<Ell3>(Ell3());
      }
    case(1):
      switch(index2 % 4){
      case(0):
	return make_shared<EllRev0>(EllRev0());
      case(1):
	return make_shared<EllRev1>(EllRev1());
      case(2):
	return make_shared<EllRev2>(EllRev2());
      case(3):
	return make_shared<EllRev3>(EllRev3());
      }
    case(2):
      switch(index2 % 4) {
      case(0):
	return make_shared<Tee0>(Tee0());
      case(1):
	return make_shared<Tee1>(Tee1());
      case(2):
	return make_shared<Tee2>(Tee2());
      case(3):
	return make_shared<Tee3>(Tee3());
      }
    case(3):
      switch(index2 % 2) {
      case(0): 
	return make_shared<Zee0>(Zee0());
      case(1):
	return make_shared<Zee1>(Zee1());
      }
    case(4):
      switch(index2 % 2) {
      case(0):
	return make_shared<ZeeRev0>(ZeeRev0());
      case(1):
	return make_shared<ZeeRev1>(ZeeRev1());
      }
    case(5):
      switch(index2 % 2) {
      case(0):
	return make_shared<Dash0>(Dash0());
      case(1):
	return make_shared<Dash1>(Dash1());
      }
    case(6):
      return make_shared<Box>(Box());
    }
  };
};

class Board {
public:
  Board() = default;
  Board(int h, int w) : height(h), width(w) {
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

  bool dropPiece(shared_ptr<PieceBase> piece, pair<int, int> loc);

  void draw() {
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
    	mvaddch(i, 2*j, grid[i][j]->draw() );
	mvaddch(i, 2*j+1, ' ' );
      }
    }         
    refresh();
  }

  bool pieceFits(shared_ptr<PieceBase> piece, pair<int, int> loc);
  ~Board() = default;

private:
  int height, width;
  vector<vector <shared_ptr<BlockBase> > > grid;
  void fillEmpty();
  int recCount(int, int);
  void recFill(int, int);
  void killLines();
};

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
    vector<shared_ptr<Block> > blocks = piece->getBlocks();
    for (auto b : blocks) {
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
	  if (c == 4) {
	    recFill(i,j);
	  }
	  // Otherwise do nothing	 
	}
      }     
    }
  }
  // Unmark all blank in a second double loop here.
  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[0].size(); j++) {
      // If blank, do a recursive count. Mark checked blocks
      grid[i][j]->mark = false;   
    }
  }
  return;
}

int Board::recCount(int i,int j) {
  if (!(grid[i][j]->isBlank() )) { return 0; }
  if (grid[i][j]->mark) {return 0; }
  grid[i][j]->mark = true;
  int u;
  int d;
  int l;
  int r;
  if (i-1 >= 0) {
    u = recCount(i+1,j);
  }
  if (i+1 < grid.size()) {
    d = recCount(i+1,j);
  }
  if (j-1 >= 0) {
    l = recCount(i,j-1);
  }
  if (j+1 < grid[0].size()) {
    r = recCount(i,j+1);
  }
  return 1+u+d+l+r;
}

void Board::recFill(int i,int j) {
  if (!(grid[i][j]->isBlank())) { return; }
  grid[i][j] = make_shared<FireBlock>( FireBlock(i,j) );
  if (i-1 >= 0) {
    recFill(i+1,j);
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

class Game {
private:
  pair<int, int> loc;
  Board board;
  RandomPieceFactory RPF;
  vector<shared_ptr<PieceBase> > pieces;
  void drawPieces() {
      pieces.front()->draw(loc);
      pair<int, int> queuePos(1, 15);
      for (int i = 1; i < pieces.size(); i++) {
	pieces[i]->draw(queuePos);
	queuePos.first += 5;
      }
  }
public:
  Game() { 
    srand(time(NULL));
    board = Board(20,10);
    RPF = RandomPieceFactory(); 
  }
  void run() {
    initscr();			/* Start curses mode 		*/
    start_color();		/* Start the color functionality */
    cbreak();			/* Line buffering disabled, Pass on
				   all things to me. This means that
				   getch() does not wait until return
				   is pressed*/
    keypad(stdscr, TRUE);	/* I need that nifty F1 */
    noecho();
    init_pair(1, COLOR_CYAN, COLOR_BLACK);

    /*nodelay(stdscr, TRUE);*/ //This line can be used prevents
			       //getch() from waiting for
			       //input. Useful in games like settings.
    /* Initialize the window parameters */
    
    refresh();
    loc = make_pair(1, 5);
    // Get pieces:
    for (int i = 0; i < 5; i++) {
      pieces.push_back(RPF.getPiece());
    }
    int ch = 0;
    
    do {
      switch(ch) {
      case KEY_LEFT:
	loc.second--;
	if (!board.pieceFits(pieces.front(), loc)) loc.second += 1;
	break;
      case KEY_RIGHT:
	loc.second++;
	if (!board.pieceFits(pieces.front(), loc)) loc.second -= 1;
	break;
      case KEY_UP:
	break;
      case KEY_DOWN:
	board.dropPiece(pieces.front(), loc);
	// Get piece
	pieces.push_back(RPF.getPiece());
	reverse(pieces.begin(), pieces.end());
	pieces.pop_back();
	reverse(pieces.begin(), pieces.end());
	// reset loc
	loc.second = 5;
	break;
      } 
      clear();
      board.draw();
      drawPieces();
      move(0,0);
      if (!board.pieceFits(pieces.front(), loc)) break;
    } while ((ch = getch()) != KEY_F(1)); 
    endwin();			/* End curses mode */
    return;
  }
};

int main() {
  Game g;
  g.run();
  return 0;
}
