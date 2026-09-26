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
string airFilterGenerator(string make, int year, int cylinders) {

  // Extract Uppercase first char of make.
  char make_first = toupper(make[0]);
  // Convert to string and extract last 
  string y_string = to_string(year).substr(2,2);
  string c_string = to_string(cylinders);


  if(c_string.length() == 1) {
      c_string = '0' + c_string;
  }

  return make_first + y_string + c_string;
  
}

int main()
{
  string filter = airFilterGenerator("Honda", 2015, 8);
  std::cout << filter << '\n';
}

