//cards.h
//Authors: Danming Wang
//All class declarations go here

#ifndef CARDS_H
#define CARDS_H
class Card {
public:
    Card(char s, int v,Card* n);
    char get_suits()const;
    int get_value()const;
    bool operator==(const Card& b);
    Card* next=nullptr;
private:
    const char suits;
    const int value;
};

class CardList {

public:

    CardList();              // constructor
    void append(Card c); // append value at end of list
    void print() const;     // print values separate by ' '
    int count() const;      // return count of values

    ~CardList();                      // destructor
    CardList(const CardList& source); //copy constructor (deep copy)
    bool contains(Card c) const;  // true if value in list
    void insertFirst(Card c);     // insert new first value
    void deleteCard(Card c); // delete the matching card from the CardList
    CardList& operator=(const CardList& source); //overloaded  (NO CHANGE)

private:

    Card *first; // pointer to first node (DO NOT CHANGE):
};
/*
class player {
public: 
private:
    CardList l;
};
*/
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
