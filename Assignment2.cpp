#include "Assignment2.h"
#include <iostream>

using namespace std;


GameOfLife::GameOfLife(){

}

GameOfLife::~GameOfLife(){
  delete myArrayRow;
  delete myArrayCol;

}

void GameOfLife::pause(){
  cout << "Pause" << endl;
}

void GameOfLife::enter(){
  cout << "Enter" << endl;
}
