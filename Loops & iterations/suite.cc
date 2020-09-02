#include <iostream>
using namespace std;

int main()
{
  int debut(0);
  do {
    cout << "de (>= 1) ? ";
    cin >> debut;
  } while (debut < 1);

  int fin(0);
  do {
    cout << "a (>= " << debut << ") ? ";
    cin >> fin;
  } while (fin < debut);

  /*******************************************
   * Completez le programme a partir d'ici.
   *******************************************/
  // 1 a 7
  for(int i=debut;i<=fin;i++)
    {
        int back(0);
        int nb_inc(0);
        
        back = fin + 1 - i;


        while( back != 0)
        {
  
          nb_inc++;
  
            if (back % 3 == 0)
              {
                back = back + 4;
              }
            else if ((back % 3 != 0) and (back % 4 == 0) )
              {
                back = back / 2;
              }
            
            else if ((back % 3 != 0) and (back % 4 != 0) )
              {
                back = back -1;
              }
  
/*           cout << i << " -> " << back << "\n";
 */        }
  
      cout << "nb_inc:" << nb_inc << endl;

    }




  /*******************************************
   * Ne rien modifier apres cette ligne.
   *******************************************/

  return 0;
}
