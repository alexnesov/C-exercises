#include <iostream>
using namespace std;


void affiche_ligne(char elt, int nb=5);


int main(){
	affiche_ligne('*');
	affiche_ligne('+', 8);
	return 0;
}

void affiche_ligne(char elt, int nb)
{
	for(int i(0); i < nb; ++i)
	{
		cout << elt;
	}
	cout << endl;
}



