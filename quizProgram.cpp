#include <iostream>
#include <ctime>
#include <string>

char displayMenu() {
  std::string difficulty_levels[3] ={"Easy", "Moderate", "Advanced"};
  std::string greeting = "Select difficulty level of Addition & Subtraction Quiz: ";
  std::string spacer = ". ";
  std::string userInput;
  //sizeof() returns size of a type in bytes. To find length Size of array need to be divided by its first element
  //for example (4bytes x 5 elements = 20bytes) -> (20 bytes / sizeof(int = 4 bytes) = 5 elements)/
  int length = sizeof(difficulty_levels) / sizeof(difficulty_levels[0]);

  std::cout << greeting << std::endl;
  
  for (int i = 0; i < length; i++) {
      std::cout << i+1 << spacer << difficulty_levels[i] << std::endl;
      
  }
  std::getline(std::cin, userInput);  
  return userInput[0];
}

int randomInt(int min, int max) {
  return 0;
}

int* generateOperands(char difficulty) {
  //Return reference to dynamically allocated array, allocated memory need to be deleted after processing.
  int* arr = new int[2];

  return arr;
}

int displayProblem(int operand1, int operand2) {
  
  return 0;
}

bool isCorrect(int op1, int op2, int answer) {

  return false;
}

void displayMessage(bool isCorrect) {

}

void displayFinalResults(int correctAnswers, int wrongAnswers) {

}

int main() {
  char c = displayMenu();
  std::cout << c << std::endl;
  return 0;
}