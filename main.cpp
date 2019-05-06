#include <iostream>
#include <fstream>
#include <string>
#include "cards.cpp"

using namespace std;

int main(int argv, char** argc){
  if(argv != 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail()){
    cout << "Could not open file " << argc[1];
    return 1;
  }

  if (cardFile2.fail()){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  CardList l1;
  CardList l2;
  // Read each file and store cards
  while (getline (cardFile1, line) && (line.length() > 0)){
      Card a(line.at(0),line.at(1));
      l1.append(a);

  }
  cardFile1.close();

  while (getline (cardFile2, line) && (line.length() > 0)){
      Card b(line.at(0),line.at(1));
      l2.append(b);
  }
  cardFile2.close();

  // Start the game
  Player Alice, Bob;
  Alice.set=l1;
  Bob.l=l2;

  return 0;
}
