#include <string>
#include <iostream>
#include <sstream>
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
#include "Board.hpp"

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
      stringstream oss;
      oss << "Lines: " << board.linesKilled;
      addstr(oss.str().c_str());
      curs_set(0);
      if (!board.pieceFits(pieces.front(), loc)) break;
    } while ((ch = getch()) != KEY_F(1)); 
    endwin();			/* End curses mode */
    cout << "Lines: " << board.linesKilled << endl;
    return;
  }
};

int main() {
  Game g;
  g.run();
  return 0;
}
