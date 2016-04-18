#ifndef BLOCKS_AND_PIECES
#define BLOCKS_AND_PIECES

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

using namespace std;

class BlockBase {
public:
  bool mark = false;
  int i = 0;
  int j = 0;
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
  int i = 0;
  int j = 0;
  virtual int Id() { return -1; };
  bool fitsIn(vector<vector< bool> > matrix) {
    // Expects array where true is open and false is filled    
    for (auto pb : blocks) {
      if (matrix[pb->i][pb->j]) return false;
    }
    return true;
  };
  void translate(int iOffset, int jOffset) {
    for (auto bl : blocks) {
      bl->i += iOffset;
      bl->j += jOffset;
    }
    i += iOffset;
    j += jOffset;
  }
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
  int Id() { return 0; }
  Ell0() {
    blocks.push_back(make_shared<Block>(Block(0, 0, 'A') ) ); // 0
    blocks.push_back(make_shared<Block>(Block(1, 0, 'A') ) ); // 0
    blocks.push_back(make_shared<Block>(Block(2, 0, 'A') ) ); // 0 0
    blocks.push_back(make_shared<Block>(Block(2, 1, 'A') ) );
  }
};

class Ell1 : public PieceBase {
public:
  int Id() { return 1; }
  Ell1() {
    blocks.push_back(make_shared<Block>(Block(1, 0, 'A') ) ); //     0
    blocks.push_back(make_shared<Block>(Block(1, 1, 'A') ) ); // 0 0 0
    blocks.push_back(make_shared<Block>(Block(1, 2, 'A') ) ); // 
    blocks.push_back(make_shared<Block>(Block(0, 2, 'A') ) );
  }
};

class Ell2 : public PieceBase {
public:
  int Id() { return 2; }
  Ell2() {
    blocks.push_back(make_shared<Block>(Block(0, 0, 'A') ) ); // 0 0
    blocks.push_back(make_shared<Block>(Block(0, 1, 'A') ) ); //   0
    blocks.push_back(make_shared<Block>(Block(1, 1, 'A') ) ); //   0
    blocks.push_back(make_shared<Block>(Block(2, 1, 'A') ) );
  }
};

class Ell3 : public PieceBase {
public:
  int Id() { return 3; }
  Ell3() {
    blocks.push_back(make_shared<Block>(Block(1, 0, 'A') ) ); // 0 0 0
    blocks.push_back(make_shared<Block>(Block(0, 0, 'A') ) ); // 0
    blocks.push_back(make_shared<Block>(Block(0, 1, 'A') ) ); 
    blocks.push_back(make_shared<Block>(Block(0, 2, 'A') ) );
  }
};

class EllRev0 : public PieceBase {
public:
  int Id() { return 4; }
  EllRev0() {
    blocks.push_back(make_shared<Block>(Block(0, 1, 'B') ) ); //   0
    blocks.push_back(make_shared<Block>(Block(1, 1, 'B') ) ); //   0
    blocks.push_back(make_shared<Block>(Block(2, 1, 'B') ) ); // 0 0
    blocks.push_back(make_shared<Block>(Block(2, 0, 'B') ) );
  }
};

class EllRev1 : public PieceBase {
public:
  int Id() { return 5; }
  EllRev1() {
    blocks.push_back(make_shared<Block>(Block(0, 0, 'B') ) ); // 0 0 0
    blocks.push_back(make_shared<Block>(Block(0, 1, 'B') ) ); //     0
    blocks.push_back(make_shared<Block>(Block(0, 2, 'B') ) ); 
    blocks.push_back(make_shared<Block>(Block(1, 2, 'B') ) );
  }
};

class EllRev2 : public PieceBase {
public:
  int Id() { return 6; }
  EllRev2() {
    blocks.push_back(make_shared<Block>(Block(0, 0, 'B') ) ); // 0 0
    blocks.push_back(make_shared<Block>(Block(1, 0, 'B') ) ); // 0
    blocks.push_back(make_shared<Block>(Block(2, 0, 'B') ) ); // 0
    blocks.push_back(make_shared<Block>(Block(0, 1, 'B') ) );
  }
};

class EllRev3 : public PieceBase {
public:
  int Id() { return 7; }
  EllRev3() {
    blocks.push_back(make_shared<Block>(Block(0, 0, 'B') ) ); // 0
    blocks.push_back(make_shared<Block>(Block(1, 0, 'B') ) ); // 0 0 0
    blocks.push_back(make_shared<Block>(Block(1, 1, 'B') ) ); 
    blocks.push_back(make_shared<Block>(Block(1, 2, 'B') ) );
  }
};

class Tee0 : public PieceBase {
public:
  int Id() { return 8; }
  Tee0() {
    blocks.push_back(make_shared<Block>(Block(0, 0, 'C') ) ); // 0 0 0
    blocks.push_back(make_shared<Block>(Block(0, 1, 'C') ) ); //   0  
    blocks.push_back(make_shared<Block>(Block(0, 2, 'C') ) ); 
    blocks.push_back(make_shared<Block>(Block(1, 1, 'C') ) );
  }
};

class Tee1 : public PieceBase {
public:
  int Id() { return 9; }
  Tee1() {
    blocks.push_back(make_shared<Block>(Block(0, 0, 'C') ) ); // 0
    blocks.push_back(make_shared<Block>(Block(1, 0, 'C') ) ); // 0 0
    blocks.push_back(make_shared<Block>(Block(2, 0, 'C') ) ); // 0
    blocks.push_back(make_shared<Block>(Block(1, 1, 'C') ) );
  }
};

class Tee2 : public PieceBase {
public:
  int Id() { return 10; }
  Tee2() {
    blocks.push_back(make_shared<Block>(Block(0, 1, 'C') ) ); //   0
    blocks.push_back(make_shared<Block>(Block(1, 0, 'C') ) ); // 0 0 0
    blocks.push_back(make_shared<Block>(Block(1, 1, 'C') ) );
    blocks.push_back(make_shared<Block>(Block(1, 2, 'C') ) );
  }
};

class Tee3 : public PieceBase {
public:
  int Id() { return 11; }
  Tee3() {
    blocks.push_back(make_shared<Block>(Block(1, 0, 'C') ) ); //   0
    blocks.push_back(make_shared<Block>(Block(0, 1, 'C') ) ); // 0 0
    blocks.push_back(make_shared<Block>(Block(1, 1, 'C') ) ); //   0
    blocks.push_back(make_shared<Block>(Block(2, 1, 'C') ) );
  }
};

class Zee0 : public PieceBase {
public:
  int Id() { return 12; }
  Zee0() {
    blocks.push_back(make_shared<Block>(Block(0, 0, 'D') ) ); // 0 0
    blocks.push_back(make_shared<Block>(Block(0, 1, 'D') ) ); //   0 0
    blocks.push_back(make_shared<Block>(Block(1, 1, 'D') ) ); 
    blocks.push_back(make_shared<Block>(Block(1, 2, 'D') ) );
  }
};

class Zee1 : public PieceBase {
public:
  int Id() { return 13; }
  Zee1() {
    blocks.push_back(make_shared<Block>(Block(0, 1, 'D') ) ); //   0
    blocks.push_back(make_shared<Block>(Block(1, 1, 'D') ) ); // 0 0
    blocks.push_back(make_shared<Block>(Block(1, 0, 'D') ) ); // 0
    blocks.push_back(make_shared<Block>(Block(2, 0, 'D') ) );
  }
};

class ZeeRev0 : public PieceBase {
public:
  int Id() { return 14; }
  ZeeRev0() {
    blocks.push_back(make_shared<Block>(Block(1, 0, 'E') ) ); //   0 0
    blocks.push_back(make_shared<Block>(Block(1, 1, 'E') ) ); // 0 0
    blocks.push_back(make_shared<Block>(Block(0, 1, 'E') ) ); //
    blocks.push_back(make_shared<Block>(Block(0, 2, 'E') ) );
  }
};

class ZeeRev1 : public PieceBase {
public:
  int Id() { return 15; }
  ZeeRev1() {
    blocks.push_back(make_shared<Block>(Block(0, 0, 'E') ) ); // 0
    blocks.push_back(make_shared<Block>(Block(1, 0, 'E') ) ); // 0 0
    blocks.push_back(make_shared<Block>(Block(1, 1, 'E') ) ); //   0
    blocks.push_back(make_shared<Block>(Block(2, 1, 'E') ) );
  }
};

class Dash0 : public PieceBase {
public:
  int Id() { return 17; }
  Dash0() {
    blocks.push_back(make_shared<Block>(Block(0, 0, 'F') ) ); // 0 0 0 0
    blocks.push_back(make_shared<Block>(Block(0, 1, 'F') ) ); // 
    blocks.push_back(make_shared<Block>(Block(0, 2, 'F') ) ); // 
    blocks.push_back(make_shared<Block>(Block(0, 3, 'F') ) );
  }
};

class Dash1 : public PieceBase {
public:
  int Id() { return 16; }
  Dash1() {
    blocks.push_back(make_shared<Block>(Block(0, 0, 'F') ) ); // 0
    blocks.push_back(make_shared<Block>(Block(1, 0, 'F') ) ); // 0
    blocks.push_back(make_shared<Block>(Block(2, 0, 'F') ) ); // 0
    blocks.push_back(make_shared<Block>(Block(3, 0, 'F') ) ); // 0
  }
};

class Box : public PieceBase {
public:
  int Id() { return 18; }
  Box() {
    blocks.push_back(make_shared<Block>(Block(0, 0, 'G') ) ); // 0 0
    blocks.push_back(make_shared<Block>(Block(0, 1, 'G') ) ); // 0 0
    blocks.push_back(make_shared<Block>(Block(1, 0, 'G') ) ); // 
    blocks.push_back(make_shared<Block>(Block(1, 1, 'G') ) ); // 
  }
};

#endif
