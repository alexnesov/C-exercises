#include <iostream>
using namespace std;

void f(int& x)
{
	x = x +1;
	cout << "x=" << x;
}

int main()
{
	int val(1);
	f(val);
	cout << " val=" << val << endl;
	return 0;
}

// x = 2
// val = 2
// Reference
