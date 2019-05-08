// testcards.h
//Authors: Danming Wang
//All test declarations go here

#ifndef TESTCARDS_H
#define TESTCARDS_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;
void runAll();
void test_constructor();
void test_copyconstructor();
void test_append();
void test_equal();
void test_card();

void test_destructor();
void test_remove();
void test_search();


void test_append_empty_list(); // A test case for append
void test_append_single_element_list(); // Tests cases should be independent,
            // small, fast, orthogonal
void test_equal_empty_list();
void test_card_operator_double_equal();

void START_TEST(string testname){
  cout<<"Start "<<testname<<endl;
}

void END_TEST(string testname) {
  cout<<"End "<<testname<<endl<<endl;
}

void assertEquals(string expected, string actual, string testDescription){
  if (expected == actual) {
    cout<<"PASSED " << endl;
  } else {
    cout<< "  FAILED: "<< testDescription << endl <<"   Expected: "<< expected << " Actual: " << actual << endl;
  }
}

void print_vector(vector<string> v){
    cout<<"{ ";
    for (int i=0;i<v.size();i++){
        cout<<v[i]<<", ";
    }
    cout<<"}"<<endl;
}

void assertEquals(vector<string> expected, vector<string> actual, string testDescription){
  if (expected == actual) {
    cout<<"PASSED " << endl;
  } else {
    cout<< "  FAILED: "<< testDescription << endl <<"   Expected: ";
    print_vector(expected);
    cout<< " Actual: ";
    print_vector(actual);
  }
}

void assertEquals(Card *expected, Card *actual, string testDescription){
  if(!actual&&!expected){
      cout<<"PASSED "<<testDescription<<endl;
  }
  while(expected){
      if (actual->info!=expected->info){
          cout<<"FAILED: "<<testDescription<<endl;
      }
      expected=expected->next;
      actual=actual->next;
  }
  cout<<"PASSED " << endl;
}



#endif
