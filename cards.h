//cards.h
//Authors: Danming Wang
//All class declarations go here

#ifndef CARDS_H
#define CARDS_H
class Card {
public:
    Card(string i){info = i;}
    ~Card(){delete next;}
    string get_info()const;
    bool operator==(const Card& b);
    Card* next=nullptr;
    Card* prev=nullptr;
private:
    const string info;
};

class CardList {

public:

    CardList();              // constructor
    void append(Card c); // append value at end of list
    void print() const;     // print values separate by ' '

    ~CardList();                      // destructor
    CardList(const CardList& source); //copy constructor (deep copy)
    bool contains(Card c) const;  // true if value in list
    void insertFirst(Card c);     // insert new first value
    void deleteCard(Card c); // delete the matching card from the CardList
    CardList& operator=(const CardList& source); //overloaded  (NO CHANGE)

private:

    Card *first; // pointer to first node (DO NOT CHANGE):
};

class Player {
public: 
    Player(string n){ name=n;}
    friend void play(CardList& l1, CardList& l2);
    friend ostream& operator<<(ostream& os, const Player& random){
        os<< random.name;
        return os;
    }
    Card* getfirst(){return list.first;}

private:
    string name="default";
    Card* head; // head ptr to the CardList
};

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
