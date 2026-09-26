/*
* Three pieces of info required:
* make String - make of a car
* year int - year of manufacture
* cylinders int - number of cylinders in the engine
* 
* Returns:
* airFilterNo string:
* 5 characters long
* 1 - 1st uppercase letter of make
* 2,3 - last to digits of a year
* 4,5 - number of cylinders
*/

#include <cctype>
#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

/* 
*  @brief Generate a string containing filter model number.
*
*  Output consists of 5 characters, where first char is an uppercase first letter of make.
*  The second and third characters represent last two digits of the year of manufacture.
*  The fourth and fifth characters are for the number of cylinders, zero-padded if number is one digit long.
*
* @param make Make of the car.
* @param year Year of the car's manufacture.
* @param cylinders The numbers of cylinders in the engine.
*
* @return The air filter model number as 5 character long string.
*/
string airFilterGenerator(string make, string year, string cylinders) {

  // Extract Uppercase first char of make.
  char make_first = toupper(make[0]);
  // Convert to string and extract last 
  string y_string = year.substr(2,2);
  string c_string = cylinders;


  if (c_string.length() == 1) {
      c_string = '0' + c_string;
  }

  return make_first + y_string + c_string;
  
}
/*
*  @brief command line interface for airFilterGenerator
*
*  Displays available options, handle user input and output result of airFilerGenerator.
*  Prompts used when function is called are stored in map prompts with descriptive names as keys.
*  
*/
void cliApp(void) {

  string userInput;
  // make, year, cylinders for storing user input.
  string m, y, c;
  // prompts map
  map<string,string> prompts {
    {"welcome","====== Welcome in Car Filter finder =======\nPlease select one of the following options:"},
    {"menu opts","1.  Find Car Filter.\n2.  Quit."},
    {"q make","Please enter the make of the vehicle."},
    {"q cylinders","Please enter the number of cylinders for "},
    {"q year","Please enter the year of the manufacture(in format YYYY) of "},
    {"res","Based on provided data, required Air Filer is: "},
    {"quitting","QUITTING..."},
    {"goodbye","Goodbye."},
    {"input error", "Input not recognised."}  };

  cout << prompts["welcome"] << '\n';
  cout << '\n' << prompts["menu opts"] << '\n';
  getline(cin,userInput);
  
  switch (userInput[0]) {
    case '1':
      cout << prompts["q make"] << endl;
      getline(cin,m);
      cout << prompts["q cylinders"] << m << endl;
      getline(cin, c);
      cout << prompts["q year"] << m << endl;
      getline(cin, y);      
      cout << prompts["res"] << airFilterGenerator(m, y, c) << endl;
      break;
    case '2':
      cout << prompts["quitting"] << endl;
      break;
    default:
      cout << prompts["input error"] << endl;
      cout << prompts["quitting"] <<endl;
  }
  
  cout << prompts["goodbye"] << endl;
}

int main()
{
  cliApp();

  return 0;
}

