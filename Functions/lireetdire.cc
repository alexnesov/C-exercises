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

int old_left;
int new_left;

int newnew;
int repetitions_chiffre(1);
int temptwo;
int lire_et_dire(int nombre);


void ajouter_chiffre_droit(int& nombre, int chiffre)
{
  newnew = repetitions_chiffre * 10 + old_left;
  cout << "ajouter_chiffre_droit : " << newnew << endl;

  // RE-INITILIZATION
  repetitions_chiffre = 0;
  old_left = new_left;
}

void dire_chiffre(int& nombre, int repetitions_chiffre, int chiffre)
{ 

/*   ajouter_chiffre_droit(nombre, chiffre);
 */  // isoler gauche
  // placer dans nombre
  // ajouter repetitions à nombre
  // ajouter chiffre à nombre

  newnew = newnew * 10 + new_left;
  cout << "Dire_chiffre: " << newnew << endl;
  

  cout << "NOMBRE : " << temptwo << endl;
  nombre = lire_et_dire(nombre);

}

int lire_et_dire(int nombre)
{

while (nombre !=0)
    {

      void calculer_repetitions(int nombre)
      {
          // repetant jusqu'a ce que le nombre manipulé soit nul
            old_left = separer_chiffre_gauche(nombre);

            cout << "OLD LEFT: " << old_left << endl;

            new_left = separer_chiffre_gauche(nombre);

            while (new_left == old_left)
            {
            
            new_left = separer_chiffre_gauche(nombre);
            cout << "NEW LEFT: " << new_left << endl;

            cout << "NOMBRE : " << nombre << endl;
            repetitions_chiffre = repetitions_chiffre +1;
            cout << " REPETITION " << repetitions_chiffre << endl;
            }
      }


      calculer_repetitions(nombre);
      cout << "chiffre old :" << old_left << endl;
      cout << "___nb of " << old_left << " : " << repetitions_chiffre << endl;
      cout << "chiffre new :" << new_left << endl;
      ajouter_chiffre_droit(nombre,repetitions_chiffre);

      temptwo = nombre;
      cout << "temptwo : " << temptwo << endl;
      dire_chiffre(nombre,repetitions_chiffre,new_left);
    }
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
