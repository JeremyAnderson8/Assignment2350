#include "Assignment2.h"
#include <iostream>

using namespace std;

//constructor
GameBoard::GameBoard(){

}

//deconstructor
GameBoard::~GameBoard(){

}

//prompts user for an input file or to input a random width, length, and density
void GameBoard::getInputInfo(){
  char response;
  bool userResponse = false;

  cout << "Would you like to read from a file ['f'] or have a random gameboard ['r']? " << endl;
  cin>>response;
  while(userResponse == false){

    if(tolower(response) == 'r'){
      //call to function to get random values
      getRandomValues();
      userResponse = true;
    }
    else if (tolower(response) == 'f'){
      //call to function to get input file info
      getFileValues();
      userResponse = true;
    }
    else{
      cout << "Invalid input" << endl;
    }
  }
}

//checks parameter to make sure inputted value is an integer
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

//prompts user for length, width, and population density
void GameBoard::getRandomValues(){
  double randNum = ((double)rand()/(double)RAND_MAX);

  cout << "Enter the width of the Game board: " << endl;

  while (!safeInt(width)){
    cout << "You have an error. " << endl;
    cout << "Give me the width of the gameboard: " << endl;
  }
  width1 = width;
  cout << "Enter the length of the Game board: " << endl;

  while (!safeInt(length)){
    cout << "You have an error. " << endl;
    cout << "Give me the length of the gameboard: " << endl;
  }
  length1 = length;
  cout << "Enter a random number between 1 and 100: " << endl;

  while (!safeInt(userRand)){
    cout << "You have an error. " << endl;
    cout << "Enter a random number between 1 and 100: " << endl;
  }
  userRand1 = userRand;
  randNumUser = (double)(userRand1 * 0.01);
  RandBoard = new char* [length1];
  for(int i = 0; i < length; ++i){
    RandBoard[i] = new char [width1];
  }

  for (int i = 0; i < length1; ++i){
    for(int j = 0; j < width1; ++j){
      randNum = ((double)rand()/(double)RAND_MAX);
      if(randNum < randNumUser){
        RandBoard[i][j] = 'X';
        cout << RandBoard[i][j] << endl;
      }
      else{
        RandBoard[i][j] = '-';
        cout << RandBoard[i][j] << endl;
      }
    }
  }
}

//reads in the length, width, and grid from the file
//couldnt get array to properly output, but can still output x or - depending on user input and randNum
void GameBoard::getFileValues(){
  int lc = 0;
  int LineRow = 0;
  int LineCol = 0;
  cout << "Please enter your file name: " << endl;
  cin >> fileName;
  userFile.open(fileName);

  if(userFile.is_open()){
    while(getline (userFile, textLine)){
      if(textLine.length() > 2){
        width = textLine.length();
        lc++;

      }
      else{
        continue;
      }
    }
    length=lc;
  }
  else{
    cout << "Cannot find file " << endl;
  }
  arr2 = new char *[length];
  int lineLen = textLine.length();

  for (int i = 0; i < length; ++i){
    arr2[i] = new char [width];
  }
  length1 = length;
  width1 = width;
  cout << length1 << endl;
  cout << width1 << endl;
  userFile.close();
}
