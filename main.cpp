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
      l1.append(line);

  }
  cardFile1.close();

  while (getline (cardFile2, line) && (line.length() > 0)){
      l2.append(line);
  }
  cardFile2.close();

  // Start the game
  CardList Alice;
  Alice.setPlayer("Alice");
  CardList Bob;
  Bob.setPlayer("Bob");
  play(Alice,Bob);
  return 0;
}
