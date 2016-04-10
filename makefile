#Define the compile command to be used:
CC=g++ -std=c++11
#Define the flags to be used with the compile statment:
CFLAGS = -g -Wall

PUGI = pugixml/

#Define the rules in the dependancy tree:
progs : superTetris tetrisFill

Utility.o : Utility.cpp Utility.hpp BlocksAndPieces.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

TetrisFiller.o : TetrisFiller.cpp TetrisFiller.hpp Utility.o
	$(CC) -c -o $@ TetrisFiller.cpp Utility.o $(CFLAGS)

Board.o : Board.cpp Board.hpp TetrisFiller.o
	$(CC) -c -o $@ Board.cpp TetrisFiller.o Utility.o $(CFLAGS)

superTetris : SuperTetris.cpp Board.o Utility.o
	$(CC) -o $@ SuperTetris.cpp Board.o Utility.o TetrisFiller.o -lncurses $(CFLAGS)

pugixml.o : $(PUGI)pugixml.cpp $(PUGI)pugixml.hpp $(PUGI)pugiconfig.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

tetrisFill : TetrisFill.cpp Utility.o TetrisFiller.o pugixml.o
	$(CC) -o $@ TetrisFill.cpp Utility.o TetrisFiller.o pugixml.o $(CFLAGS)


.PHONY: clean

clean:
	rm *.o

