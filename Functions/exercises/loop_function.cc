#include <iostream>
using namespace std;

double lire();

double lire ()
{
	double n(0.0);
	do{
	cout << "Entrez un nombre: ";
	cin >> n;
	} while (n <= 0.0);

	return n;
}


int main()
{
	lire();
}
