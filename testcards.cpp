// This file should contain unit tests for all the 
// public interfaces of the classes that you implement

#include "cards.h"
#include "testcards.h"
#include <iostream>
#include <vector>
using namespace std;

int main(){
  runAll();
  return 0;
}

void runAll(){
    test_constructor();
    test_copyconstructor();
    test_append();
    test_equal();
    test_destructor();
    test_deleteCard();
    test_contains();
    test_card();
}

void test_constructor(){
    START_TEST("test_constructor");
    CardList lst;
    cout<<" Expected: lst.name == default"<<endl;
    cout<<" Actual: lst.name == "<<lst<<endl;
    if(lst.getfirst()==nullptr){
        cout<<" PASSED: test_constructor, first ==NULL"<<endl;
    }else{
        cout<<" FAILED: test_constructor"<<endl;
    }
    END_TEST("test_constructor");
}

void test_copyconstructor(){
    START_TEST("test_copyconstructor");
    CardList list1;
    string arr[] ={"h 3","s 2","c a","c 3","h 9"};
    for(int i = 0; i<5; i++){
        list1.append(arr[i]);
    }

    CardList list2(list1);
    assertEquals(list1.vectorize(),list2.vectorize(),"test_copyconstructor");
    END_TEST("test_copyconstructor");
}

void test_append(){
  START_TEST("test_append");
  test_append_empty_list();
  test_append_single_element_list();
  END_TEST("test_append");

}

void test_equal(){
  START_TEST("test_equal");
  test_equal_empty_list();
  test_equal_single_element_list();
  END_TEST("test_equal");

}

void test_destructor(){
    START_TEST("test_destructor");
    CardList *list = new CardList;
    list->append("c 2");
    list->append("d j");
    list->append("s k");
    delete list;
    cout<<"Testing destructor, run in valgrind to check for leaks"<<endl;
    END_TEST("test_destructor");
}

void test_deleteCard(){
    string testname="test_deleteCard";
    START_TEST(testname);
    CardList lst1;
    lst1.append("c 2");
    lst1.append("c 5");
    lst1.deleteCard("c 2");
    CardList lst2;
    lst2.append("c 5");
    assertEquals(lst1.vectorize(),lst2.vectorize(),testname);
    END_TEST(testname);
}

void test_contains(){
    string testname="test_contains";
    START_TEST(testname);
    CardList lst;
    lst.append("c 2");
    lst.append("c 5");
    if(lst.contains("c 2")&&lst.contains("c 5")){
        lst.append("d j");
        lst.deleteCard("c 2");
        if(lst.contains("d j")&& !lst.contains("c 2")){
            cout<<" PASSED: "<<testname<<endl;
        }
        else{
            cout<<" FAILED: "<<testname<<endl;
        }
    }
    else{
        cout<<" FAILED: "<<testname<<endl;
    }
    END_TEST(testname);
}


void test_card(){
  START_TEST("test_card");
  test_card_operator_double_equal();
//  test_equal_single_element_list();
  END_TEST("test_card");
}


void test_append_empty_list(){ 
// A test case for append single card node to CardList
    string testname = "case 0: append Card ['c 2'] to empty CardList";
    CardList lst;
    lst.append("c 2");
    vector<string> vexp={"c 2"};
    vector<string> vact = lst.vectorize();
    if(vexp!=vact){
        cout<<" FAILED: "<<testname<<endl;
    }else{
        cout<<" PASSED: "<<testname<<endl;
    }

}

void test_append_single_element_list(){ 
    string testname = "case 1: append Card 'c 5' to single-element list with existing card 'c 2'";
    CardList lst;
    lst.append("c 2");
    lst.append("c 5");
    vector<string> vexp={"c 2", "c 5"};
    vector<string> vact=lst.vectorize();
    assertEquals(vexp,vact,testname);
}

void test_equal_empty_list(){ 
  string testname = "case 0: [], []";
  CardList l1, l2;
  assertEquals(l1.getfirst(),l2.getfirst(),"test_equal_empty_list");
}
void test_equal_single_element_list(){
    string testname = "case 1: {'c 3'},{'c 3'}";
    CardList l1,l2;
    l1.append("c 3");
    l2=l1;
    assertEquals(l1.getfirst(),l2.getfirst(),"test_equal_single_element_list");
}

void test_card_operator_double_equal(){
    string testname="test_card_operator_double_equal";
    Card c1, c2;
    c1.info="c 3";
    c2.info="c 3";
    if (c1==c2){
        assertEquals(c1.info,c2.info,testname);
    }else{
        cout<<" Failed: "<<testname<<endl;
    }   
}




