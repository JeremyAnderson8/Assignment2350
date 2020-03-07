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

 int c = 0;

 counter = 0;

 int LineRow = 0;

 int LineCol = 0;

 cout << "Please enter your file name: " << endl;

 cin >> fileName;

 userFile.open(fileName);



 if(userFile.is_open()){
   while(counter < 2){
     if(counter == 0){
       userFile >> intLineRow;
       ++counter;
     }
     else if (counter == 1){
       userFile >> intLineCol;
       ++counter;
     }
   }

   while( getline ( userFile, textLine ) ){
     int lineLen = textLine.length();
     if (lineLen == 0) continue;
     for (int i = 0; i < lineLen; ++i){
       if(textLine.at(i) == 'X'){
         ++Xcounter;
       }
     }
     cout << textLine << endl;
   }
   cout << "Num of X's: "<< Xcounter << endl;
   cout << "Rows: "<< intLineRow << endl;
   cout << "Lines: "<< intLineCol << endl;
   gameBoundary();
 }
 else{
   cout << "File could not be opened " << endl;
 }
 return 0;
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

char GameOfLife::outputSelection(){
  bool validResponse = false;
  while(validResponse == false){
    cout << "Do you want to output to a file or to the console?" << endl;
    cout << "Press 'F' to output to a file" << endl;
    cout << "Pres 'C' to output to the console" << endl;
    cin >> outputDecision;

    if(tolower(outputDecision) == 'f'){
      validResponse = true;
      outputToFile();
      break;
    }
    else if(tolower(outputDecision) == 'c'){
      validResponse = true;
      outputToConsole();
      break;
    }
  }

  return outputDecision;

}

void GameOfLife::classic(){
  cout << "classic" << endl;
  outputSelection();
}

void GameOfLife::mirror(){
  cout << "mirror" << endl;
  outputSelection();
}

void GameOfLife::doughnut(){
  cout << "doughnut" << endl;
  outputSelection();
}

void GameOfLife::outputToFile(){
  ofstream outputFile;
  outputFile.open("outputFile.txt");
}

void GameOfLife::outputToConsole(){
  bool validResponse = false;
  while(validResponse == false){
    cout << "Do you want to press enter between simulations or have the program automatically pause?" << endl;
    cout << "Press 'E' if you want to press enter." << endl;
    cout << "Press 'P' to have the program pause for you." << endl;
    cin >> pauseOrEnter;
    if(tolower(pauseOrEnter) == 'e'){
      validResponse = true;
      enter();
      break;
    }
    else if(tolower(pauseOrEnter) == 'p'){
      validResponse = true;
      pause();
      break;
    }
  }
}

void GameOfLife::pause(){
  cout << "pause" << endl;
}

void GameOfLife::enter(){
  cout << "enter" << endl;
}
