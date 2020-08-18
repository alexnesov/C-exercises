#include <iostream>
using namespace std;

int main()
{
  cout << "Donnez l'heure de début de la location (un entier) : ";
  int debut;
  cin >> debut;

  cout << "Donnez l'heure de fin de la location (un entier) : ";
  int fin;
  cin >> fin;

  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/

	int h1;
	int h2;

	bool activate(1);

	int total;

	if ( (debut < 0) or (debut > 24) or (fin < 0) or (fin > 24) )
  	{
    	cout << "Les heures doivent être comprises entre 0 et 24 !" << endl;
    }

    else if (debut == fin)
	    {
	    	cout << "Bizarre, vous n'avez pas loué votre vélo bien longtemps !" << endl;
	    }

    else if (debut > fin)
	    {
	    	cout << "Bizarre, le début de la location est après la fin ..." << endl;
		}

    else     
        {
            cout << "Vous avez louÃ© votre vÃ©lo pendant" << endl;

            if ( (debut > 17) and (fin > 17) )

                {
                h1 = fin - debut;
                h2 = 0;
                activate = 0;

                cout << h1 << " heure(s) au tarif horaire de "
                    << "1 franc(s)" << endl;
                cout << h2 << " heure(s) au tarif horaire de "
                    << "2 franc(s)" << endl;

                }
            
            if ( (debut > 7) and (fin < 17) )
                {  
                h1 = 0;
                h2 = (fin - debut);

                cout << h2 << " heure(s) au tarif horaire de "
                    << "2 franc(s)" << endl;
                }

            if ( (activate == 1) and (debut >= 7) and (fin > 17) )
                {
                h1 = (fin-17);
                h2 = (17-debut);

                cout << h1 << " heure(s) au tarif horaire de "
                    << "1 franc(s)" << endl;
                cout << h2 << " heure(s) au tarif horaire de "
                    << "2 franc(s)" << endl;
                }

            if ( (debut < 7) and (fin > 17) )
                {
                h1 = (7 - debut) + (fin - 17);
                h2 = 10;          

                cout << h1 << " heure(s) au tarif horaire de "
                    << "1 franc(s)" << endl;
                cout << h2 << " heure(s) au tarif horaire de "
                    << "2 franc(s)" << endl;
                }
                
            if ( (debut < 7) and (fin <= 17) and (fin >=7) )
                {
                h1 = 7 - debut;
                h2 = fin - 7;

                cout << h1 << " heure(s) au tarif horaire de "
                    << "1 franc(s)" << endl;
                cout << h2 << " heure(s) au tarif horaire de "
                    << "2 franc(s)" << endl;    
                }

            if ( (debut < 7) and (fin <= 7) )
                {
                h1 = fin-debut;
                h2 = 0;

                cout << h1 << " heure(s) au tarif horaire de "
                    << "1 franc(s)" << endl;
 
                }

        total = (h1 * 1) + (h2 * 2);

        cout << "Le montant total Ã  payer est de "
        << total << " franc(s)." << endl;
        }

  /*******************************************
   * Ne rien modifier après cette ligne.
   *******************************************/

  return 0;
}