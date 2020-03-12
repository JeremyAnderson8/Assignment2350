#include "Assignment2.h"
#include <iostream>

using namespace std;

//constructor
Classic::Classic(){

}

//deconstructor
Classic::~Classic(){

}

//making gameboard with classic boundaries
void Classic::startClassic(){
  // have to write game bounds
  GameBoard gameBoard;

  //spent hours on this
  //not sure why it won't work
  //prevented further progess
  //tried to access length and width from GameBoard class
  length = gameBoard.length1;
  width = gameBoard.width1;

  cout << length << endl;
  cout << width << endl;

  char ** arr = gameBoard.RandBoard;
  cout << "This is the classic mode" << endl;
  nextArr = new char*[length];

  //code that shouldve outputted array in the correct format
  for(int i = 0; i < length; i++){
    nextArr[i] = new char[width];
  }

  for(int i = 0; i < length; i++){
    for(int j = 0; j < width; j++){
      if(1 < 2){
        cout << arr[i][j];
      }
    }
  }
}
