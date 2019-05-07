//cards.cpp
//Authors: Danming Wang
//Implementation of the classes defined in cards.h
#include "cards.h"

// copy constructor
CardList::CardList(const CardList& source) {
    first=nullptr;
    Card* p = source.first;
    while(p){
        this->append(p->info);
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
bool CardList::contains(string i) const {
    Card* p = first;
    while(p){
        if (p->info == i){
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

Card* CardList::get(string i){
    Card* p = first;
    if (p==nullptr){
        return nullptr;
    }
    else {
        while(p->info!=i&&p){
            p=p->next;
        }
        if (!p){
            return nullptr;
        }
        return p;
    }
}
void CardList::deleteCard(string i){
    Card* p = first;
    Card* prev = p;
    Card* n= p->next;
    while(p->info!=i){
        prev=p;
        p=p->next;
        n=p->next;
    }
    prev->next=n;
    delete p;
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
        l.append(q->info);
        q=q->next;
    }
    return l;
    
}

Card* CardList::getfirst(){
    return first;
}


// append value at end of list
void CardList::append(string i) {
    if (first == 0) { // empty list
        first = new Card;
        first->info=i;
        first->next=0;
    }
    else {
        Card *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Card;
        n->next->info=i;
        n->next->next = 0;
    }
}

// prCard cs enclose in [], separated by spaces
void CardList::print() const {
    Card *n = first;
    while (n) {
        cout << n->info<<endl;
        n = n->next;
    }
    cout<<endl;
}

void play(CardList& l1, CardList& l2){
    CardList match;
    Card* p1 = l1.getfirst();
    while(p1){
        if (l2.contains(p1->info)){
            match.append(p1->info);
        }
        p1=p1->next;
    }
    while(match.getfirst()){
    cout <<l1<<" picked matching card ";
    Card* m1=l1.getfirst();
    while(!l2.contains(m1->info)){
        m1=m1->next;
    }
    cout << m1->info<<endl;
    l1.deleteCard(m1->info);
    l2.deleteCard(m1->info);
    match.deleteCard(m1->info);
    if (!match.getfirst()){
        break;}
    cout <<l2<<" picked matching card ";
    Card* m2=l2.getfirst();
    while(!l1.contains(m2->info)){
        m2=m2->next;
    }
    cout << m2->info<<endl;
    l1.deleteCard(m2->info);
    l2.deleteCard(m2->info);
    match.deleteCard(m2->info);
    if(!match.getfirst()){
        break;
    }
    }
    cout <<l1<<"'s cards: \n";
    l1.print();
    cout<<l2<<"'s cards: \n";
    l2.print();
}
