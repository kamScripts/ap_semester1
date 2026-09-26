// CarFilter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
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
using namespace std;
string airFilterGenerator(string make, int year, int cylinders) {
    string yearString = to_string(year);
    string cylindersString = to_string(cylinders);

}

int main()
{
    std::cout << "Hello World!\n";
}

