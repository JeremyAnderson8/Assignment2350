#include "Assignment2350.h"
#include <iostream>

using namespace std;


GameBoard::GameBoard(){
  char response;
  bool userResponse = false;

  cout << "Would you like to read from a file ['f'] or have a random gameboard ['r']? " << endl;
  cin>>response;
  while(userResponse == false){

    if(tolower(response) == 'r'){
      getRandomValues();
      userResponse = true;
    }
    else if (tolower(response) == 'f'){
      getFileValues();
      userResponse = true;
    }
    else{
      cout << "Invalid input" << endl;
    }
  }

}


GameBoard::~GameBoard(){

}

bool GameBoard::safeInt(int &output){
  int temp;
  cin>>temp;
  if (cin.fail()) {
    cin.clear();
    cin.ignore();
    return false;
  }
  output = temp;
  return true;

}

void GameBoard::getRandomValues(){
  int width = 0;
  int length = 0;
  int popDen = 0;
  double randNum = ((double)rand()/(double)RAND_MAX);


  cout << "Enter the width of the Game board: " << endl;
  cin >> width;
  while (!safeInt(width)){
    cout << "You have an error. " << endl;
    cout << "Give me the width of the gameboard: " << endl;

  }

  cout << "Enter the legnth of the Game board: " << endl;
  cin >> length;

  while (!safeInt(length)){
    cout << "You have an error. " << endl;
    cout << "Give me the length of the gameboard: " << endl;

  }
  cout << "Enter a random number between 1 and 100: " << endl;
  cin >> popDen;

  while (!safeInt(popDen)){
    cout << "You have an error. " << endl;
    cout << "Give me the Population Density (as a percent) of the gameboard: " << endl;

  }


  RandBoard = new char* [length];
  for(int i = 0; i < length; ++i){
    RandBoard[i] = new char [width];
  }

  for (int i = 0; i < width; ++i){
    for(int j = 0; j < length; ++j){
      if(RandVar < probOfX){
        RandBoard[i][j] = 'X';
      }
      else{
        RandBoard[i][j] = '-';
      }
    }
  }
}

void GameBoard::getFileValues(){
  int c = 0;
  int LineRow = 0;
  int LineCol = 0;
  cout << "Please enter your file name: " << endl;
  cin >> fileName;
  userFile.open(fileName);

  if(userFile.is_open()){
    while(getline (userFile, textLine ) ){
      width+=textLine.length();
      c++;
    }
    length=c;
  }
  else{
    cout << "Cannot find file " << endl;
  }
  arr2 = new char *[length];
  int lineLen = textLine.length();

  for (int i = 0; i < length; ++i){
    arr2[i] = new char [width];
  }
  userFile.close();
}
