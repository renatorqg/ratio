#include <iostream>
#include <ratio.h>

using namespace std;

int main()
{
  cout << "Hello ratio" << endl;
	Ratio x(22,7), y(-3,8), z;
	z = x; // using the assignment operator 
	z.print(); cout << endl;
	x = y*z; // using the multiplication operator
	x.print(); cout << endl;
	return 0;
}
