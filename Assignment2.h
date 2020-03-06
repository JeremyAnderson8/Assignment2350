#include <iostream>
#include <typeinfo>
#include <fstream>
#include <random>
#include <string>

using namespace std;

class GameOfLife{

public:

  GameOfLife();//default constructor

  GameOfLife(int mSize); // overloaded constructor

  ~GameOfLife();//deconstructor

  //aux functions

  char userInput(); // ask user random or file
  string inputFile(); // ask for name of inputFile
  int getRandomInput(); //prompt fopr when a random game board is chosen
  char gameBoundary();
  void doughnut();
  void mirror();
  void classic();
  bool safeInt(int &output);
  bool safeStr(string &outputS);
  int GetFileInfo();



  //vars

  int output;
  int maxSize;
  char userResponse1;
  int randomWidth;
  int randomLength;
  int populationDen;
  double populationDenCalc;
  string fileName;
  string textLine;
  int intLineRow;
  int intLineCol;
  int counter;
  ifstream userFile;
  string userBoundary;
  string outputS;

  char *myArrayRow;
  char *myArrayCol;





};
