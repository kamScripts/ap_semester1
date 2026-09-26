#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>

char displayMenu() {
  std::string difficulty_levels[3] ={"Easy", "Moderate", "Advanced"};
  std::string greeting = "Select difficulty level of Addition & Subtraction Quiz: ";
  std::string spacer = ". ";
  std::string user_input;
  //sizeof() returns size of a type in bytes. To find length Size of array need to be divided by its first element
  //for example (4bytes x 5 elements = 20bytes) -> (20 bytes / sizeof(int = 4 bytes) = 5 elements)/
  int length = sizeof(difficulty_levels) / sizeof(difficulty_levels[0]);

  std::cout << greeting << '\n';

  for (int i = 0; i < length; i++) {
      std::cout << i+1 << spacer << difficulty_levels[i] << std::endl;
      
  }
  std::getline(std::cin, user_input);  
  return user_input[0];
}

int randomInt(int min, int max) {  
  int random = min + (rand() % (max - min + 1));
  return random;
}

int* generateOperands(char difficulty) {
  //Return reference to dynamically allocated array, allocated memory need to be deleted after processing.
  // op1, op2, operator
  
  int* arr = new int[2];
  int min, max;

  //Decide operands range on difficulty provided
  switch (difficulty) {
    case 1:
      min = 1;
      max = 10;
      break;
    case 2:
      min = 10;
      max = 99;     
      break;
    case 3:
      min = 100;
      max = 9999;
      break;
    default:
      min = 0;
      max = 0;
  };
  // Generate operands
  arr[0] = randomInt(min, max);
  arr[1] = randomInt(min, max);
  return arr;
}
char randomOperator() {
  // Generate random operator between + and -
  bool random = rand() % 2 == 1;
  if (random) {
    return '-';
  }
  return '+';
}

int displayProblem(int operand1, int operand2, char sign) {

  std::string user_input;

  std::cout << operand1 << ' ' << sign << ' ' << operand2 << " = ____" << std::endl;
  getline(std::cin, user_input);

  // user input converted to int.
  return std::stoi(user_input);
}

bool isCorrect(int op1, int op2, char sign, int answer) {
  
  return false;
}

void displayMessage(bool isCorrect) {

}

void displayFinalResults(int correctAnswers, int wrongAnswers) {

}
void testFuncs() {
  std::cout << "==== randomInt test ====" << '\n';

  std::cout << "range 0-20" << '\n';
  std::cout << randomInt(0, 20) << '\t';
  std::cout << randomInt(0, 20) << '\t';
  std::cout << randomInt(0, 20) << '\t';
  std::cout << randomInt(0, 20) << '\n';
  std::cout << randomInt(100, 999) << '\t';
  std::cout << randomInt(100, 999) << '\t';
  std::cout << randomInt(100, 999) << '\t';
  std::cout << randomInt(100, 999) << '\n';


  std::cout << "*** end of test ***" << std::endl;

  std::cout << "=== Generate Operands & Operation sign test ===\n" ;

  std::cout<<"Difficulty: Advanced\tOperand range: 100-9999\n";

  int * problem = generateOperands(3);
  char op  = randomOperator();

  std::cout << problem[0] << ' ' << op << ' ' << problem[1] << '\n';
  delete[] problem;

  std::cout<<"Difficulty: Moderate\tOperand range: 10-99\n";

  problem = generateOperands(2);
  op  = randomOperator();

  std::cout << problem[0] << ' ' << op << ' ' << problem[1] << '\n';
  delete[] problem;
  
  std::cout<<"Difficulty: Easy\tOperand range: 1-9\n";

  problem = generateOperands(2);
  op  = randomOperator();

  std::cout << problem[0] << ' ' << op << ' ' << problem[1] << '\n';
  delete[] problem;

  std::cout << "*** end of test ***" << std::endl;

  std::cout << "=== Display Problem test ===\n" ;

  int user_input;
  int counter = 5;
  while (counter>0) {
    problem = generateOperands(randomInt(1, 3));
    op = randomOperator();
    int answer = displayProblem(problem[0], problem[1], op);
    std::cout << "user answer: " << answer << std::endl;
    delete[] problem;
    counter--;
  }
}
int main() {
  srand(time(0));
  testFuncs();
  //char c = displayMenu();
  //std::cout << c << std::endl;
  return 0;
}