//Paint calculator task
/*
* Formula  N= ((P * nc * S) + W (1 + 1/nd)
* N - number of gallons of paint to purchase
* P - 0.004, the internationl Painter's constant
* nc - number of children in vicinity of the structure to be painted
* S - surface are to be painted
* W - 1.2, the expected for any job
* nd - expected number of days to complete the job
*/

#include <iostream>
#include <math.h>



using namespace std;
/*
* calcPaint - Calculate number of gallons of paint
* 
* nc (int)   number of children in vicinity of the structure to be painted.
* s  (float) surface are to be painted.
* nd (int)   expected number of days to complete the job.
*
* Returns:
* (int) 
*/
int calcPaint(int nc, float s, int nd ) {
  
  const float W = 1.2f;
  const float P = 0.004f;
  float result = ((P * nc * s) + W) * (1 + (1 / nd));
  // Handle edge case when result is an integer and increment or if not round the result up
  if (result == (int) result) {
    result += 1;
  } else {
    ceil(result);
  }    

  return (int) result;
}

int main()
{
  float s;
  int nc;
  int nd;
  cout << "Welcome to the painter calculator..." << endl;
  cout << "Please enter the surface are to be painted: " << endl;
  cin >> s;
  cout << "Please enter the number of children in vicinity of the structure to be painted: " << endl;
  cin >> nc;
  cout << "Please enter the expectedd number of days to complete the job: ";
  cin >> nd;
  cout << "Number of gallons of paint to purchase: " << calcPaint(nc, s, nd) << endl;
  cout << "Surface are to paint: " << s << endl;
  cout << "Children in a vicinity: " << nc << endl;
  
    
}

