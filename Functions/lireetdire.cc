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



int repetition;
int resultat;
int chiffre_init;
int chiffre;
int new_chiffre;
bool init = true;

void ajouter_chiffre_droit(int& nombre, int chiffre)
{
  resultat = resultat * 10 + chiffre;
}

void dire_chiffre(int& nombre, int repetitions_chiffre, int chiffre)
{
  resultat = resultat * 10 + repetition;
  ajouter_chiffre_droit(nombre, chiffre);
  repetition = 1;
}

int lire_et_dire(int nombre)
{
  cout << endl;
  bool multi;
  int repetitions_chiffre;

  chiffre = separer_chiffre_gauche(nombre);
  cout << "CHIFFRE : " << chiffre << endl;

  do
  {
    do
    {
      new_chiffre = separer_chiffre_gauche(nombre);
      repetition++;
    } while (chiffre==new_chiffre);

    cout << "CHIFFRE : " << chiffre << endl;
    cout << "NEW CHIFFRE : " << new_chiffre << endl;
    cout << "REPETITION : " << repetition << endl;
    cout << "NOMBRE : " << nombre << endl;
    cout << endl;

    dire_chiffre(nombre, repetitions_chiffre=repetition, chiffre);

    if((nombre==0)&&(new_chiffre!=0))
    // Second condition for
    // when n=0 AND digit alone at the end of the number: i.e "11221"
    {
      dire_chiffre(nombre, repetitions_chiffre=1,chiffre=new_chiffre);
    }





    // Re-initilizations
    repetition=0;
    chiffre=new_chiffre;

  } while (nombre!=0);
  
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
