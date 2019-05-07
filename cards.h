//cards.h
//Authors: Danming Wang
//All class declarations go here

#ifndef CARDS_H
#define CARDS_H
#include <iostream>
#include <string>
using namespace std;

class Card {
public:
    Card(){}
    ~Card(){}
    Card* next=nullptr;
    string info;
};

class CardList {

public:
    CardList():first(nullptr){}
    void setPlayer(string n){player=n;}
    Card* getfirst();
    Card* get(string i);
    void append(string i); // append value at end of list
    void print() const;     // print values separate by ' '

    ~CardList();                      // destructor
    CardList(const CardList& source); //copy constructor (deep copy)
    bool contains(string i) const;  // true if value in list
    void deleteCard(string i); // delete the matching card from the CardList
    CardList& operator=(const CardList& source); //overloaded  (NO CHANGE)
    friend ostream& operator<<(ostream& os, const CardList& random){
        os<< random.player;
        return os;
    }
    friend void play(CardList& l1, CardList& l2);

private:
    string player="default";
    Card *first; // pointer to first node (DO NOT CHANGE):
};

void play(CardList& l1, CardList& l2);
#endif

// Use this file to define all your classes and public functions
// You should design your program with OOP prinicples using classes
// An example of class design would be having Card, CardList and Player as Classes.
// Card represent Card in your LinkedList which has some data in it
// CardList can be your LinkedList Class which has operations such as append, remove etc
// Player class represents your game player
// Think about the public functions that should be part of each class. (All public function need to be tested in unit testing)
// One of the important functions is search / find which is essential for players to find cars in their opponent's "hand"
// Make sure you overload the desired operators
// This is not the fixed design. We are not expecting exactly 3 classes. You can do with less or more.
// Important thing to consider is abstraction.
