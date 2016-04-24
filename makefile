#Define the compile command to be used:
CC=g++ -std=c++11
#Define the flags to be used with the compile statment:
CFLAGS = -g -Wall

PUGI = pugixml/

#Define the rules in the dependancy tree:
progs : tetromino19 tetrominoFill

Utility.o : Utility.cpp Utility.hpp BlocksAndPieces.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

TetrominoFiller.o : TetrominoFiller.cpp TetrominoFiller.hpp Utility.o
	$(CC) -c -o $@ TetrominoFiller.cpp $(CFLAGS)

Board.o : Board.cpp Board.hpp TetrominoFiller.o
	$(CC) -c -o $@ Board.cpp $(CFLAGS)

tetromino19 : Tetromino19.cpp Board.o Utility.o
	$(CC) -o $@ Tetromino19.cpp Board.o Utility.o TetrominoFiller.o -lncurses $(CFLAGS)

pugixml.o : $(PUGI)pugixml.cpp $(PUGI)pugixml.hpp $(PUGI)pugiconfig.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

tetrominoFill : TetrominoFill.cpp Utility.o TetrominoFiller.o pugixml.o
	$(CC) -g -o $@ TetrominoFill.cpp Utility.o TetrominoFiller.o pugixml.o $(CFLAGS)

.PHONY: clean

clean:
	rm *.o tetromino19 tetrominoFill

