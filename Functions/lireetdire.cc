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

int resultat(0);


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


  int temp2;
  int temp3;
  int diff;
  int memory;
  int chiffre;
  int repetitions_chiffre(1);
  bool init = true;
  bool previous_multiple = false;

  while(nombre!=0)
  {
    cout << endl;
    cout << endl;
    
    if(init==true)
    {
          temp2 = separer_chiffre_gauche(nombre);
          cout << "TEMP2: " << temp2 << endl;

          temp3 = separer_chiffre_gauche(nombre);
          cout << "TEMP3: " << temp3 << endl;

          init = false;
    }
    else
    {
          temp2 = temp3;
          temp3 = separer_chiffre_gauche(nombre);
    }

    cout << "INIT : " << init << endl;
    diff = temp3 - temp2;
    cout << "diff : " << diff << endl;


    if(diff==0)
    {
        previous_multiple = true;
        memory = temp2;
        repetitions_chiffre++;
    }
    else
    {
        if(previous_multiple==true)
        {
            dire_chiffre(nombre,repetitions_chiffre,chiffre=memory);
            
        }
        else
        {
            dire_chiffre(nombre,repetitions_chiffre,chiffre=temp3);
        }
        
        // Re-initilization
        repetitions_chiffre = 1;
        previous_multiple = false;
    }
        
    cout << "TEMP 3 : " << temp3 << endl;
  }

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
