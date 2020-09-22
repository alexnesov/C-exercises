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

int temp2;
int temp3;
int repeated;
bool repeated_act();
int resultat(0);
int chiffre;
int repetitions_chiffre(1);

void ajouter_chiffre_droit(int& nombre, int chiffre)
{
  resultat = resultat * 10 + chiffre;
}

void dire_chiffre(int& nombre, int repetitions_chiffre, int chiffre)
{
  resultat = resultat * 10 + repetitions_chiffre;
  ajouter_chiffre_droit(nombre, chiffre);
}

int lire_et_dire(int nombre)
{

  // jusqu'a ce que le nombre manipulé soit nul

  while(nombre!=0)
  {
    temp2 = separer_chiffre_gauche(nombre);
    temp3 = separer_chiffre_gauche(nombre);
    
    if (temp2==temp3)
    {
      repetitions_chiffre++;
    }
    else
    {
      chiffre=temp2;
      dire_chiffre(nombre, repetitions_chiffre, chiffre);
    }
    
    cout << "TEMP2: " << temp2 << endl;
    cout << "TEMP3: " << temp3 << endl;
  }

  cout << repetitions_chiffre << endl;

  return resultat;
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
