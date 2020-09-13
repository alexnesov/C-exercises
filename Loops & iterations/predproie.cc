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
  double day_before(0.0);

  float attaque_debut(1);
  float attaque_fin(1);

  bool lapin_risk = false;
  bool renard_risk = false;
  
  bool lapin_ext = false;
  bool renard_ext = false;

  bool init = true;

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

            {

                if (init==true)
                  {      
                    nb_lapins = lapins_i * (1.0 + taux_croissance_lapins - taux_attaque * renards_i); 
                    day_before = nb_lapins;
                    nb_renards = renards_i * (1.0 + taux_attaque * lapins_i * taux_croissance_renards - taux_mortalite);
                    init = false;
                  }
                else 
                {
                  nb_lapins = nb_lapins * (1.0 + taux_croissance_lapins - taux_attaque * nb_renards);  
                  nb_renards = nb_renards * (1.0 + taux_attaque * day_before * taux_croissance_renards - taux_mortalite);
                  day_before = nb_lapins;
                }
                  cout << "Après " << i << " mois, il y a " << nb_lapins << " lapins et " << nb_renards << " renards" << endl;

            }
      }


  // ===== PARTIE 3 =====
  // Variation du taux d'attaque

  do {
  cout << "taux d'attaque au départ en % (entre 0.5 et 6) ? " << endl;
  cin >> attaque_debut;
  }while(attaque_debut<0.5 || attaque_debut>6);

  do {
  cout << "taux d'attaque à la fin  en % (entre ";
  cout << " et 6) ? " << endl;
  cin >> attaque_fin;
  }while(attaque_fin<1 || attaque_fin>6);

  for(float j=attaque_debut;j<attaque_fin;j++)
  {
      int end(50);
      cout <<  endl << "***** Le taux d'attaque vaut "<< j << "%" <<  endl;
      taux_attaque = j/100;

      for(int i=1;i<=50;i++)
      {

            {

                if (init==true)
                  {      
                    nb_lapins = lapins_i * (1.0 + taux_croissance_lapins - taux_attaque * renards_i); 
                    day_before = nb_lapins;
                    nb_renards = renards_i * (1.0 + taux_attaque * lapins_i * taux_croissance_renards - taux_mortalite);
                    init = false;
                  }
                else 
                {
                  nb_lapins = nb_lapins * (1.0 + taux_croissance_lapins - taux_attaque * nb_renards);  
                  nb_renards = nb_renards * (1.0 + taux_attaque * day_before * taux_croissance_renards - taux_mortalite);
                  day_before = nb_lapins;
                }


                if(nb_lapins<5)
                {
                  lapin_risk = true;
                }

                if(nb_lapins<2)
                {
                  lapin_ext = true;
                  nb_lapins = 0;
                }

                if(nb_renards<5)
                {
                  renard_risk = true;
                }

                if(nb_renards<2)
                {
                  renard_ext = true;
                  nb_renards = 0;
                }

                if((nb_lapins <2) and (nb_renards <2))
                {
                  lapin_ext = true;
                  nb_lapins = 0;
                  renard_ext = true;
                  nb_renards = 0;
                  end = i;
                  break;
                }
              }

      }  // LOOP I

    if (end < 50)
    {
      cout << "Après " << end << " mois, il y a " << nb_lapins << " lapins et " << nb_renards << " renards" << endl;
    }
    else
    {
      cout << "Après " << duree << " mois, il y a " << nb_lapins << " lapins et " << nb_renards << " renards" << endl;
    }


    // RENARDS
    if (renard_risk==true)
      {
          cout << "Les renards ont été en voie d'extinction" << endl;
          if (renard_ext==true)
            {
              cout << "et les renards ont disparu :-(" << endl;
            }
          else
            {
              cout << "mais la population est remontée ! Ouf !" << endl;
            }
      }


    // LAPINS
    if (lapin_risk==true)
      {
        cout << "Les lapins ont été en voie d'extinction" << endl;
        if (lapin_ext==true)
        {
            cout << "et les lapins ont disparu :-(" << endl;
        }
        else
        {
            cout << "mais la population est remontée ! Ouf !" << endl;
        }
      }
    



    // BOTH EXTINCT
    if ((lapin_risk == false) and (renard_risk == false))
      {
        cout << "Les lapins et les renards ont des populations stables." << endl;
      }

    // RE-INITILIZATIONS
    init = true;
    lapin_risk = false;
    lapin_ext = false;
    renard_risk = false;
    renard_ext = false;

  } // LOOP J
    

  /*******************************************
   * Ne rien modifier après cette ligne.
   *******************************************/

  return 0;
}
