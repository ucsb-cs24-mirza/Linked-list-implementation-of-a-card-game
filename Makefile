# Makefile
# created by Danming Wang, 04/22/2019

CXX_FLAG = --std=c++11 -g

all: main cards

main: main.o
	g++ $(CXX_FLAG) -o main main.o

cards: cards.o
	g++ $(CXX_FLAG) -o cards.o

main.o: main.cpp
	g++ -c $(CXX_FLAG) main.cpp

cards.o: cards.cpp
	g++ -c $(CXX_FLAG) cards.cpp

clean:
	rm -f main cards *.o
