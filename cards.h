//cards.h
//Authors: Danming Wang
//All class declarations go here

#ifndef CARDS_H
#define CARDS_H
#include <iostream>
#include <string>
#include <vector>
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
    ~CardList();
    void setPlayer(string n){player=n;}
    Card* getfirst();
//    Card* get(string i);
    void append(string i); // append value at end of list
    void print() const;     // print values in the list

    CardList(const CardList& source); //copy constructor (deep copy)
    bool contains(string i) const;  // true if value in list
    void deleteCard(string i); // delete the matching card from the CardList
    CardList& operator=(const CardList& source); 
    vector<string> vectorize();
    friend ostream& operator<<(ostream& os, const CardList& random){
        os<< random.player;
        return os;
    }
    friend void play(CardList& l1, CardList& l2);

private:
    string player="default";
    Card *first; 
};

void play(CardList& l1, CardList& l2);
#endif

