#include <iostream>
#include <typeinfo>
#include <fstream>
#include <random>
#include <string>
#include <cmath>

using namespace std;

//class that is supposed to take in the paramters from either the user or the input filt to create 2D array
class GameBoard{
public:
  GameBoard(); //constructor
  ~GameBoard(); //deconstructor

  //functions
  void getRandomValues();
  void getFileValues();
  bool safeInt(int &output);
  void outputToFile();
  void getInputInfo();

  //vars
  int width;
  int widthTemp;
  int lengthTemp;
  int probOfX;
  int length;
  int width1;
  int length1;
  int userRand1;
  int userRand;
  double randNumUser;
  string fileName;
  string textLine;
  ifstream userFile;
  int RandVar;
  char pausesOrEnter;


  char ** arr1 = NULL;
  char ** arr2 = NULL;
  char ** RandBoard = NULL;


};
//created new class for each of the gamemodes
//idea provided to me by the tutoring center
class Classic{
public:
  Classic(); //constructor
  ~Classic(); //deconstructor

  //function
  void startClassic();

  //vars
  char ** nextArr = NULL;
  int width;
  int length;
  int width6;
  int length6;
  int width1;
  int length1;

  int neighborCounter;


};
class Mirror{
public:
  Mirror(); //constructor
  ~Mirror(); //deconstructor

  //functions
  void startMirror();

  //vars
  char ** nextArr = NULL;
  int width;
  int length;

};
class Doughnut{
public:
  Doughnut(); //constructor
  ~Doughnut(); //deconstructor

  //functions
  void startDoughnut();

  //vars
  char ** nextArr = NULL;
  int width;
  int length;

};
