#include <iostream>
using namespace std;

int main()
{

    bool foret(0);
    bool chap_conv(0);
    bool anneau(0);
    bool lamelles(0);

    cout << "Pensez à un champignon : amanite tue-mouches, pied bleu, girolle," << endl
    << "cèpe de Bordeaux, coprin chevelu ou agaric jaunissant." << endl << endl;
    
    cout << "Est-ce que votre champignon vit en forêt (1 : oui, 0 : non) ? ";
    cin >> foret;

    if (foret == 0)
        {
            cout << "Est-ce que votre champignon a un chapeau convexe (1 : oui, 0 : non) ? ";
            cin >> chap_conv;
            
            if (chap_conv == 1)
                {
                    cout << "==> Le champignon auquel vous pensez est ";
                    cout << "l'agaric jaunissant";
                }
            else
                {
                    cout << "==> Le champignon auquel vous pensez est ";
                    cout << "le coprin chevelu";
                }
        }
    
    else
        {
            cout << "Est-ce que votre champignon a un chapeau convexe (1 : oui, 0 : non) ? ";
            cin >> chap_conv;
            
            if (chap_conv == 1)
                {
                    cout << "Est-ce que votre champignon a un anne0au (1 : oui, 0 : non) ? ";
                    cin >> anneau;

                    if (anneau == 1)
                    {
                        cout << "==> Le champignon auquel vous pensez est ";
                        cout << "l'amanite tue-mouches";
                    }
                    else
                    {
                        cout << "==> Le champignon auquel vous pensez est ";
                        cout << "le pied bleu";
                    }
                }
            else
                {
                    cout << "Est-ce que votre champignon a des lamelles (1 : oui, 0 : non) ? ";
                    cin >> lamelles;
                    if (lamelles == 1)
                    {
                        cout << "==> Le champignon auquel vous pensez est ";
                        cout << "la girolle";
                    }
                    else
                    {
                        cout << "==> Le champignon auquel vous pensez est ";
                        cout << "le cèpe de Bordeaux";
                    }
                }
        }
  return 0;
}