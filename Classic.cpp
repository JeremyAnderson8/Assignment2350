#include "Assignment2.h"
#include <iostream>

using namespace std;
Classic::Classic(){

}

Classic::~Classic(){

}

void Classic::startClassic(){
  cout << "This is the classic mode" << endl;
  // have to write game bounds
  GameBoard *gameBoard = new GameBoard();

  length = gameBoard->length;
  width = gameBoard->width;


  char ** arr = gameBoard->RandBoard;

  for(int i = 0; i < width; i++){
    for(int j = 0; j < length; j++){

    }
  }
}
