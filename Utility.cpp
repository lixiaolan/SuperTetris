#include "Utility.hpp"

// rotate by i*pi/2 radiants ccw
void rotatePiece(shared_ptr<PieceBase> piece, unsigned i) {
  i %= 4;
  if (i == 0) return;

  if (i == 1) {
    for (auto bl : piece->getBlocks()) {
      int temp = bl->i;
      bl->i = - bl->j;
      bl->j = temp;
    }
    return;
  }

  if (i == 2) {
    for (auto bl : piece->getBlocks()) {
      bl->i = - bl->i;
      bl->j = - bl->j;
    }
    return;
  }

  if (i == 3) {
    for (auto bl : piece->getBlocks()) {
      int temp = bl->j;
      bl->j = - bl->i;
      bl->i = temp;
    }
    return;
  }

  return;
}

// Translate piece by offset vector
void translatePiece(shared_ptr<PieceBase> piece, int iOffset, int jOffset) {
  for (auto bl : piece->getBlocks()) {
    bl->i += iOffset;
    bl->j += jOffset;
  }
  return;
}

// Function to enumerate all ppossible pieces anchored at 0,0. The
// index should be less than 76.
shared_ptr<PieceBase> getAnchoredPiece(unsigned index)
{

  // 0
  // 0
  // 0 0
  if (index < 16) {
    shared_ptr<PieceBase> ptr = make_shared<Ell0>(Ell0());
    
    if (index >= 4) {
      translatePiece(ptr, -1, 0);
    }
    if (index >= 8) {
      translatePiece(ptr, -1, 0);
    }
    if (index >= 12) {
      translatePiece(ptr, 0, -1);
    }
    
    rotatePiece(ptr, index % 4);
    return ptr;
  }

  // 0 0 0
  //     0  
  if (index < 32) {
    index = index % 16;
    shared_ptr<PieceBase> ptr = make_shared<EllRev1>(EllRev1());
    
    if (index >= 4) {
      translatePiece(ptr, 0, -1);
    }
    if (index >= 8) {
      translatePiece(ptr, 0, -1);
    }
    if (index >= 12) {
      translatePiece(ptr, -1, 0);
    }
    
    rotatePiece(ptr, index % 4);
    return ptr;
  }

  // 0 0 0
  //   0
  if (index < 48) {
    index = index % 16;
    shared_ptr<PieceBase> ptr = make_shared<Tee0>(Tee0());
    
    if (index >= 4) {
      translatePiece(ptr, 0, -1);
    }
    if (index >= 8) {
      translatePiece(ptr, -1, 0);
    }
    if (index >= 12) {
      translatePiece(ptr, 1, -1);
    }
    
    rotatePiece(ptr, index % 4);
    return ptr;
  }  

  // 0 0  
  //   0 0
  if (index < 56) {
    index = index % 8;
    shared_ptr<PieceBase> ptr = make_shared<Zee0>(Zee0());
    
    if (index >= 4) {
      translatePiece(ptr, 0, -1);
    }
    
    rotatePiece(ptr, index % 4);
    return ptr;
  }  

  // 0  
  // 0 0
  //   0
  if (index < 64) {
    index = index % 8;
    shared_ptr<PieceBase> ptr = make_shared<ZeeRev1>(ZeeRev1());
    
    if (index >= 4) {
      translatePiece(ptr, -1, 0);
    }
    
    rotatePiece(ptr, index % 4);
    return ptr;
  }

  // 0 0 0 0
  if (index < 72) {
    index = index % 8;
    shared_ptr<PieceBase> ptr = make_shared<Dash0>(Dash0());
    
    if (index >= 4) {
      translatePiece(ptr, 0, -1);
    }
    
    rotatePiece(ptr, index % 4);
    return ptr;
  }

  // 0 0
  // 0 0
  if (index < 76) {
    index = index % 4;
    shared_ptr<PieceBase> ptr = make_shared<Box>(Box());    
    
    rotatePiece(ptr, index % 4);
    return ptr;
  }

  return nullptr;
}

shared_ptr<PieceBase> RandomPieceFactory::getPiece() {
  int index = rand() % 19;
  switch (index) {
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

shared_ptr<PieceBase> RandomPieceFactory2::getPiece() {
  int index1 = rand();
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
