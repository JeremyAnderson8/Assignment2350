#include "Assignment2.h"

GameOfLife::GameOfLife(){
  myArrayRow = new char(200);
  myArrayCol = new char(200);
  maxSize = 200;
}


GameOfLife::GameOfLife(int mSize){

  myArrayRow = new char(mSize);

  myArrayCol = new char(mSize);

  maxSize = mSize;

}



GameOfLife::~GameOfLife(){

  delete myArrayRow;

  delete myArrayCol;

}



char GameOfLife::userInput(){

  bool validResponse = false;
  while(validResponse == false){

    cout << "Press ['r'] for a random gameboard, press ['f'] if you have a file: " << endl;

    cin >> userResponse1;



    if(tolower(userResponse1) == 'r'){

      getRandomInput();

      validResponse = true;

      break;

    }

    else if(tolower(userResponse1) == 'f'){

      GetFileInfo();

      validResponse = true;

      break;

    }

  }

  return userResponse1;

}



bool GameOfLife::safeInt(int &output){
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

bool GameOfLife::safeStr(string &outputS){
  string temp;
  cin>>temp;
  if (cin.fail()) {
    cin.clear();
    cin.ignore();
    return false;
  }
  outputS = temp;
  return true;
}



int GameOfLife::getRandomInput(){
  while(true){
    cout << "You have selected a random gameboard. " << endl;
    cout << "Give me the width of the gameboard: " << endl;

    while (!safeInt(randomWidth)){
      cout << "You have an error. " << endl;
      cout << "Give me the width of the gameboard: " << endl;
    }

    cout << "The width is: " << randomWidth << endl;
    cout << "Give me the length of the gameboard: " << endl;

    while (!safeInt(randomLength)){
      cout << "You have an error. " << endl;
      cout << "Give me the length of the gameboard: " << endl;
    }

    cout << "The length is : " << randomLength << endl;
    cout << "What percent of the board do you want your population density to be?" << endl;

    while (!safeInt(populationDen)){
      cout << "You have an error. " << endl;
      cout << "Give me the population density: " << endl;
    }

    populationDenCalc = populationDen * .01;
    cout << "The population density is: " << populationDenCalc << endl;
    break;

  }

}

 int GameOfLife::GetFileInfo(){
    string fileName = "";
    cout << "Please Enter The Name Of A File: " << endl;
    cin >> fileName;

    ifstream userFile;
    userFile.open(fileName);

    if(userFile.fail())
    {
      cerr << "Error Opening File" << endl;
      exit(1);
    }

    int rowVal = 0;
    int colVal = 0;
    counter = 0;

    if(userFile.is_open()){
        while(counter < 2){
          if(counter == 0){
            userFile >> rowVal;
          }
          else if(counter == 1){
            userFile >> colVal;
          }
          counter++;
        }

    }
    cout << rowVal << endl;
    cout << colVal << endl;
    gameBoundary();
    userFile.close();

    return 1;

}

char GameOfLife::gameBoundary(){
  bool validResponse = false;
  while(validResponse == false){
    cout << "Which game mode would you like?" << endl;
    cout << "Enter 'C' for Classic" << endl;
    cout << "Enter 'M' for Mirror" << endl;
    cout << "Enter 'D' for Doughnut" << endl;
    cin >> userResponse1;
    if(tolower(userResponse1) == 'c'){
      validResponse = true;
      classic();
      break;
    }
    else if(tolower(userResponse1) == 'm'){
      validResponse = true;
      mirror();
      break;
    }
    else if(tolower(userResponse1) == 'd'){
      validResponse = true;
      doughnut();
      break;
    }

  }

  return userResponse1;

}

void GameOfLife::classic(){
  cout << "classic" << endl;
}

void GameOfLife::mirror(){
    cout << "mirror" << endl;
}

void GameOfLife::doughnut(){
    cout << "doughnut" << endl;
}
