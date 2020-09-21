#include <iostream>
using namespace std;

int separer_chiffre_gauche(int& nombre)
{
  int dix(1);
  int temp(nombre);
  while (temp >= 10) {
    dix  *= 10;
    temp /= 10;
  }
  nombre %= dix;
  return temp;
}

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/
int chiffre(0);
int tempone(0);
int old_left;
int newnew;


void ajouter_chiffre_droit(int& nombre, int chiffre)
{
  newnew = tempone * 10 + old_left;
  cout << "NEW NEW : " << newnew << endl;
}

void dire_chiffre(int& nombre, int repetitions_chiffre, int chiffre)
{ 
  nombre = lire_et_dire(nombre);
}

int lire_et_dire(int nombre)
{
  int new_left;

  old_left = separer_chiffre_gauche(nombre);
  
  do{
    new_left = separer_chiffre_gauche(nombre);
    tempone = tempone +1;
  }while (new_left == old_left);



  cout << "chiffre old :" << old_left << endl;
  cout << "nb of " << old_left << " : " << tempone << endl;
  cout << "chiffre new :" << new_left << endl;
  ajouter_chiffre_droit(nombre,tempone);

  return nombre;
}
 
/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

void repeter_lire_et_dire(int& nombre, int fois)
{
  while (fois-- > 0) {
    nombre = lire_et_dire(nombre);
  }
}

int main()
{
  int nombre(1);
  int fois(1);
  cin >> nombre >> fois;
  repeter_lire_et_dire(nombre, fois);
  cout << nombre << endl;
  return 0;
}
