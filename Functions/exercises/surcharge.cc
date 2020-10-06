#include <iostream>
using namespace std;

int f(int a=3);

int main()
{
	int r;
	int d;
	int h(0);
	int k(5);

	r=f();
	d=f(10.0);

	cout << r << endl;
	cout << d << endl;


	double x(f(5));
	cout << (5==f(h)) << endl;
}





int f(int a)
{
	return a;
}
