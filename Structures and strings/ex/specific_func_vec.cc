#include <iostream>
#include <vector>
using namespace std;



void saisie(vector<int>& vect, size_t taille = 4)
    {
        int t(0);
        vect.clear();
        cout << "Saisir de " << taille << " valeurs :" << endl;
        
        while ((vect.size() < taille) && (t<10)){
            cout << "Entrez la valeur " << vect.size() << " : ";
            int val;
            cin >> val;
            if ( (val < 0) and (not vect.empty()) ) { vect.pop_back();      }
            else if (val == 0)                      { vect.clear();         }
            else if (val > 0)                       { vect.push_back(val);  }
            t++;
        }
    }

vector<int> ages(5);


int main(){
    saisie(ages);
}