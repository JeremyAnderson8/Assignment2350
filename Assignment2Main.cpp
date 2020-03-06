#include "Assignment2.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {

  GameOfLife *myGame = new GameOfLife(200);

  myGame->userInput();

  delete myGame;

  return 0;

}
