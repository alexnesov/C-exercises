#include <iostream>
#include <iomanip> // pour setprecision()
using namespace std;

int main()
{
  // Réduire le format d'affichage
  cout << setprecision(4);

  // Paramètres
  double taux_croissance_lapins(0.3);
  double taux_attaque(0.01);
  double taux_croissance_renards(0.008);
  double taux_mortalite(0.1);
  int duree(50);

  double renards_i(0.0);
  double lapins_i(0.0);

  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/

  // ===== PARTIE 1 =====
  // Saisie des populations initiales
  double nb_renards(0.0);
  double nb_lapins(0.0);
  double inter(0.0);

  do {
  cout << "Combien de renards au départ (>= 2) ? ";
  cin >> renards_i;
  }while(renards_i<2);

  do{
  cout << "Combien de lapins au départ  (>= 5) ? ";
  cin >> lapins_i;
  }while(lapins_i<5);
  // ===== PARTIE 2 =====
  // Première simulation


  cout <<  endl << "***** Le taux d'attaque vaut "<< taux_attaque * 100 << "%" <<  endl;
  for(int i=1;i<=50;i++)
  {

    if ((nb_renards==0) and (nb_lapins==0))
    {
      nb_lapins = lapins_i * (1.0 + taux_croissance_lapins - taux_attaque * renards_i); 
      inter = nb_lapins;
      nb_renards = renards_i * (1.0 + taux_attaque * lapins_i * taux_croissance_renards - taux_mortalite);
    }
    else 
    {
      nb_lapins = nb_lapins * (1.0 + taux_croissance_lapins - taux_attaque * nb_renards);  
      nb_renards = nb_renards * (1.0 + taux_attaque * inter * taux_croissance_renards - taux_mortalite);
      inter = nb_lapins;
    }

    cout << "Après " << i << " mois, il y a " << nb_lapins << " lapins et " << nb_renards << " renards" << endl;

  }

  // ===== PARTIE 3 =====
  // Variation du taux d'attaque

    cout << "Après " << duree << " mois, il y a " << nb_lapins << " lapins et " << nb_renards << " renards" << endl;

  cout << endl;

  cout << "taux d'attaque au départ en % (entre 0.5 et 6) ? ";

  cout << "taux d'attaque à la fin  en % (entre ";
  cout << " et 6) ? ";

  cout << "Les renards ont été en voie d'extinction" << endl;
  cout << "mais la population est remontée ! Ouf !" << endl;
  cout << "et les renards ont disparu :-(" << endl;
  cout << "Les lapins ont été en voie d'extinction" << endl;
  cout << "mais la population est remontée ! Ouf !" << endl;
  cout << "et les lapins ont disparu :-(" << endl;
  cout << "Les lapins et les renards ont des populations stables." << endl;

  /*******************************************
   * Ne rien modifier après cette ligne.
   *******************************************/

  return 0;
}
