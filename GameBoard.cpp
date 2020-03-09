#include "Assignment2.h"
#include <iostream>

using namespace std;


GameBoard::GameBoard(){


}

GameBoard::~GameBoard(){

}

void GameBoard::getInputInfo(){
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
  double randNum = ((double)rand()/(double)RAND_MAX);

  cout << "Enter the width of the Game board: " << endl;
  while (!safeInt(width)){
    cout << "You have an error. " << endl;
    cout << "Give me the width of the gameboard: " << endl;
  }

  cout << width << endl;
  cout << "Enter the length of the Game board: " << endl;

  while (!safeInt(length)){
    cout << "You have an error. " << endl;
    cout << "Give me the length of the gameboard: " << endl;

  }
  cout << "Enter a random number between 1 and 100: " << endl;

  while (!safeInt(userRand)){
    cout << "You have an error. " << endl;
    cout << "Enter a random number between 1 and 100: " << endl;

  }


  RandBoard = new char* [length];
  for(int i = 0; i < length; ++i){
    RandBoard[i] = new char [width];
  }

  for (int i = 0; i < width; ++i){
    for(int j = 0; j < length; ++j){
      randNum = ((double)rand()/(double)RAND_MAX);
      if(randNum < userRand){
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
