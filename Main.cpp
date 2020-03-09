#include "Assignment2350.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  char outputDecision;
  bool validResponse1 = false;
  while(validResponse1 == false){
    cout << "Do you want to output to a file (press ['f']), or console (press ['c'])? " << endl;
    cin >> outputDecision;
    if(tolower(outputDecision) == 'f') {
      validResponse1 = true;
      //outputToFile();
      break;
    }
    else if(tolower(outputDecision) == 'c') {
      char pausesOrEnter = ' ';
      cout << "Do you want to press enter between simulations (press ['e']) or just wait for a brief pause (press['p']) " <<endl;
      cin>>pausesOrEnter;
      bool validResponse = false;
      while(validResponse == false){
        if(tolower(pausesOrEnter) == 'e'){
          //enter();
          validResponse= true;
          break;

        }
        else if(tolower(pausesOrEnter) == 'p'){
          //pause();
          validResponse= true;
          break;
        }
        else{
          cout << "Not a valid input" << endl;
        }
      }
    }
    else{
      cout << "Not a valid input" << endl;
    }
  }
  GameOfLife *myGame = new GameOfLife();
  char userResponse;

  bool validResponse = false;
  while(validResponse == false){
    cout << "Which game mode would you like?" << endl;
    cout << "Enter 'C' for Classic" << endl;
    cout << "Enter 'M' for Mirror" << endl;
    cout << "Enter 'D' for Doughnut" << endl;
    cin >> userResponse;
    if(tolower(userResponse) == 'c'){
      Classic classic;
      classic.startClassic();
      validResponse = true;
      break;
    }
    else if(tolower(userResponse) == 'm'){
      Mirror mirror;
      mirror.startMirror();
      validResponse = true;
      break;
    }
    else if(tolower(userResponse) == 'd'){
      Doughnut doughnut;
      doughnut.startDoughnut();
      validResponse = true;
      break;
    }
  }

  delete myGame;

  return 0;
}
