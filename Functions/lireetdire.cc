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
  bool re_init =false;
  chiffre = separer_chiffre_gauche(nombre);

  do
  {

    if(re_init==true)
    {
      chiffre = separer_chiffre_gauche(nombre);
    }

    do
    {
      new_chiffre = separer_chiffre_gauche(nombre);
      repetition++;
    } while (chiffre==new_chiffre);

    // if multiple
    // if not multiple

 
    cout << "nombre: " << nombre;
    cout << endl;
    cout << "repetition(s) : " << repetition << endl;
    dire_chiffre(nombre, repetition,chiffre);
    
    if(new_chiffre!=0)
    {
      dire_chiffre(nombre, repetition,chiffre=new_chiffre);
    }

    // Re-initilizations
    repetition=0;
    chiffre=0;
    re_init=true;


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
