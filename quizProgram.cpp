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
  //  Returns pointer to dynamically allocated array, allocated memory need to be deleted after processing.
  

  int* arr = new int[2]; // pointer to empty array of size 2.
  int min, max;

  //Decide operands range on difficulty provided
  switch (difficulty) {
    case '1':
      min = 1;
      max = 10;
      break;
    case '2':
      min = 10;
      max = 99;     
      break;
    case '3':
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

  if (sign == '+') {
    return op1 + op2 == answer;
  }
  return op1 - op2 == answer;
}

void displayMessage(bool isCorrect) {
  
  if (isCorrect) {
      std::cout << "correct" << std::endl;
    } else {
      std::cout << "incorrect" << std::endl;
    }
}

void displayFinalResults(int correctAnswers, int wrongAnswers, double attempts) {
  
  int percentage = (int)((double)correctAnswers / attempts * 100);

  std::cout << "you answered in correctly in " << percentage << "%\n";
  std::cout << "Correct answers:\t" << correctAnswers << '\n' << "Incorrect answers:\t" << wrongAnswers << std::endl;

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

  std::cout << "=== Display Problem + isCorrect test ===\n" ;

  int user_input;
  int trials = 10;
  int counter = 10;
  int user_correct = 0;
  int user_wrong = 0;

  while (counter>0) {
    problem = generateOperands(randomInt(1, 3));
    op = randomOperator();
    int correctAnswer;    
    int answer = displayProblem(problem[0], problem[1], op);
    

    if (op == '+') {
      correctAnswer = problem[0] + problem[1];
    } else {
      correctAnswer = problem[0] - problem[1];
    }
    std::cout << "user answer: " << answer << std::endl;
    bool userAnswer = isCorrect(problem[0], problem[1], op, answer);
    if (userAnswer) {
      displayMessage(userAnswer);
      user_correct++;
    } else {
      displayMessage(userAnswer);
      user_wrong++;
    }    
    delete[] problem;
    counter--;
  }
  
  displayFinalResults(user_correct, user_wrong, trials);

}
int main() {
  srand((int)time(0));
  //testFuncs();
  bool isPlaying = true;

  while (isPlaying) {

    int* problem;
    int counter, trials, temp;
    std::string user_trials_input;
    char diff_level, op;
    int user_correct = 0;
    int user_wrong = 0;

    std::cout << "=== Welcome in mathematical quiz, check your knowledge in maths! ===\n";

    diff_level = displayMenu();
    

    std::cout << "How many problems would you like to solve ?" << std::endl;
    getline(std::cin, user_trials_input);

    temp = std::stoi(user_trials_input);
    counter = temp;
    trials = temp;

    while (counter>0) {

    problem = generateOperands(diff_level);

    op = randomOperator();
    int correctAnswer;    
    int answer = displayProblem(problem[0], problem[1], op);
    

    if (op == '+') {
      correctAnswer = problem[0] + problem[1];
    } else {
      correctAnswer = problem[0] - problem[1];
    }
    // check if user is correct
    bool userAnswer = isCorrect(problem[0], problem[1], op, answer);

    if (userAnswer) {
      displayMessage(userAnswer);
      user_correct++;
    } else {
      displayMessage(userAnswer);
      // give user one more attempt
      std::cout << "try one more time!" << std::endl;
      answer = displayProblem(problem[0], problem[1], op);
      if (userAnswer) {
      displayMessage(userAnswer);
      user_correct++;
    } else {
      displayMessage(userAnswer);
      // after second attempt wrongAnswers++
      std::cout << "correct answer is " << correctAnswer << std::endl;
      user_wrong++;
    }    

    }    
    delete[] problem; // delete dynamically allocated array.
    counter--;
  }
  
  displayFinalResults(user_correct, user_wrong, trials);

  isPlaying = false;
  }
  
  return 0;
}