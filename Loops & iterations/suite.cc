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
        int nb_inc(0);
        int not_back = i;
        

        while( not_back != 0)
        {
  
          nb_inc++;
  
            if (not_back % 3 == 0)
              {
                not_back = not_back + 4;
              }
            else if ((not_back % 3 != 0) and (not_back % 4 == 0) )
              {
                not_back = not_back / 2;
              }
            
            else if ((not_back % 3 != 0) and (not_back % 4 != 0) )
              {
                not_back = not_back -1;
              }
  
       }
  
      cout << i << " -> " << nb_inc << endl;

    }




  /*******************************************
   * Ne rien modifier apres cette ligne.
   *******************************************/

  return 0;
}
