//cards.cpp
//Authors: Danming Wang
//Implementation of the classes defined in cards.h
#include "cards.h"

#include <iostream>
using namespace std;
Card::Card(char s, int v, Card* n): suits(s),value(v){
    next=n;
}

char Card::get_suits() const{
    return suits;
}

int Card::get_value() const{
    return value;
}

bool Card::operator==(const Card& b){
    if (this->get_suits()==b.get_suits() && this->get_value()==b.get_value()){
        return true;
    }
    else {
        return false;
    }
    // compare Card* next
}

// copy constructor
CardList::CardList(const CardList& source) {
    first=nullptr;
    Card* p = source.first;
    while(p){
        this->append(*p);
        p=p->next;
    }
}

// destructor deletes all nodes
CardList::~CardList() {
    Card* p = first;
    Card* temp;
    while(p){
        temp=p->next;
        delete p;
        p=temp;
    }
}

// returns true if value is in the list; false if not
bool CardList::contains(Card c) const {
    Card* p = first;
    Card* q = &c;
    while(p!=NULL){
        if (p == q){
            return true;
        }
        p=p->next;
    }
    return false;
}

// inserts value as new node at beginning of list
void CardList::insertFirst(Card c) {
    Card *p=&c;
    p->next=first;
    first = p;
}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
CardList& CardList::operator=(const CardList& source){
    Card* tmp;
    CardList&l = *this;
    Card* p = l.first;
    while(p){
        tmp=p->next;
        delete p;
        p=tmp;
    }
    l.first=nullptr;
    Card* q = source.first;
    while(q){
        l.append(*q);
        q=q->next;
    }
    return l;
    
}



// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// constructor sets up empty list
CardList::CardList() : first(0) { }


// append value at end of list
void CardList::append(Card c) {
    if (first == 0) { // empty list
        first = &c;
        first->next=0;
    }
    else {
        Card *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = &c;
        n->next->next = 0;
    }
}

// prCard cs enclose in [], separated by spaces
void CardList::print() const {
    Card *n = first;
    cout << '[';
    while (n) {
        cout << n->get_suits()<<" "<<n->get_value()<<",";
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}


// return count of values
int CardList::count() const {
    int result = 0;
    Card *n = first;
    while (n) {
        ++result;
        n = n->next;
    }
    return result;
}
