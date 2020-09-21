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

void ajouter_chiffre_droit(int& nombre, int chiffre)
{
  nombre = nombre *10 + chiffre;
}

void dire_chiffre(int& nombre, int repetitions_chiffre, int chiffre)
{

}

int lire_et_dire(int nombre)
{
  int chiffre_old;
  int chiffre_new;

  int temp2(1);

  cout << temp2 << endl;
  chiffre_old = separer_chiffre_gauche(nombre);
  do{
    chiffre_new = separer_chiffre_gauche(nombre);
    cout << chiffre_new << endl;
    temp2+1;
  }while (chiffre_new == chiffre_old);


  cout << "chiffre old :" << chiffre_old << endl;
  cout << "chiffre new :" << chiffre_new << endl;
  cout << "temp2 : " << temp2;
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
