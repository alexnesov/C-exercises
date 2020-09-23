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

int n1;
int n2;
int repetitions_chiffre(1);
int resultat;
int diff;
int single_digit;
int chiffre;

void ajouter_chiffre_droit(int& nombre, int chiffre)
{
   resultat = resultat * 10 + chiffre;
 }

void dire_chiffre(int& nombre, int repetitions_chiffre, int chiffre)
{
    cout << "chiffre dans dire_chiffre: " << chiffre << endl;
    resultat = resultat * 10 + repetitions_chiffre;
    ajouter_chiffre_droit(nombre,chiffre);
}


int lire_et_dire(int nombre)
{

  cout << endl;
  cout << "PROGRAM: " <<endl;
  ////////////////////////
  single_digit = nombre/10;
  if(single_digit<1)
  {
    single_digit=true;
  }
  else
  {
    single_digit=false;
  }
  ////////////////////////

  if(single_digit==true)
  {
    dire_chiffre(nombre,repetitions_chiffre=1,chiffre=nombre);
  }
  else
  { 
    chiffre = separer_chiffre_gauche(nombre);
    cout << "chiffre : " << chiffre << endl;
    cout << "nombre : " << nombre << endl;
        
         while (nombre!=0)
         {
          n2 = separer_chiffre_gauche(nombre);
          cout << "N2 : " << n2 << endl;

          if(n2==chiffre)
            {
              cout << endl;
              cout << " A " << endl; 
              cout << "repetitions: " << repetitions_chiffre << endl;
              cout << "chiffre : " << chiffre << endl;
              cout << "N2 : " << n2 << endl;

              repetitions_chiffre++;
              chiffre=n2;
            }
          else
            {
              cout << endl;
              cout << " B " << endl; 
              cout << "repetitions: " << repetitions_chiffre << endl;
              cout << "chiffre : " << chiffre << endl;
              cout << "N2 : " << n2 << endl;

              dire_chiffre(nombre,repetitions_chiffre,chiffre);
              repetitions_chiffre = 1;

              cout << "Résultat : " << resultat << endl;

            }
         }

          cout << endl;
          // Last loop, because we'll need it eventhough h will be be equal to 0          
          if(n2==chiffre)
            {
              cout << endl;
              cout << " C " << endl; 
              cout << "repetitions: " << repetitions_chiffre << endl;
              cout << "chiffre : " << chiffre << endl;
              cout << "N2 : " << n2 << endl;

              repetitions_chiffre++;
              chiffre=n2;
            }
          else
            {
              cout << endl;
              cout << " D " << endl; 
              cout << "repetitions: " << repetitions_chiffre << endl;
              cout << "chiffre : " << chiffre << endl;
              cout << "N2 : " << n2 << endl;

              dire_chiffre(nombre,repetitions_chiffre,chiffre=n2);
              repetitions_chiffre = 1;

              cout << "Résultat : " << resultat << endl;

            }
          ////////////////////////////////////////////////////

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
