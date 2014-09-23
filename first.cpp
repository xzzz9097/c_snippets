/*
	Simple program that sums two numbers given in input.
	Uses input/output library.
*/	
 
#include <iostream>
using namespace std;

int main()
{
	// Initialize vars
	int a = 0, b = 0;

	// Get the inputs
	cin >> a;
  cin >> b;

  // Do the math
  int sum = a + b;

  // Output the result
  cout << sum;

  // Return code
  return 0;
}