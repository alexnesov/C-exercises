#include <iostream>
#include <vector>
using namespace std;

/*******************************************
 * Complétez le programme à partir d'ici.
 *******************************************/

typedef vector<vector<int>> Carte;
typedef vector<vector<int>> Matrix;

struct Position
{
  int i; // row
  int j; // column
};


bool binaire(Carte const& carte)
{
  bool true_false(true);
  int x(0);
  for(auto row : carte)
  {
      for(auto elem : row)
      {
          if(elem>1 || elem<0)
          {
            x=x+1;
          }
      }
  }

  if(x>0)
  {
      true_false = false;
  }

  return true_false;
} 

void affiche(Carte const& carte)
{
  for(auto row : carte)
  {
        for(auto col : row)
        {
          cout << col;
        }
        cout << endl;
  }
  cout << endl;
  cout << "----";
  cout << endl;
}

void test_display(Matrix v)
{
  //cout << "Size of plan (n. cols): " << carte[0].size() << endl;

  for(auto row : v)
  {
    for(auto col : row)
    {
      cout << " " << col;
    }
    cout << endl;
  }

  cout << endl;
}

Matrix mapOnes(Carte carte)
{
  // The objective is the get the positions of the first and 
  // last one for every row to be able to fill al the space in between with 1's
  
  int pos_col(0);
  vector<int> indices;
  Matrix all_ones;

  for(auto row : carte)
  {
    for(auto col : row)
    {
      if(col==1)
      {
        indices.push_back(pos_col);
      }
      pos_col++;
    }
    all_ones.insert(all_ones.end(),indices);

    // re-initilizations
    pos_col = 0; indices.clear();
  }
  // test_display(all_ones); // To remove
  return all_ones;
}

Matrix mapFirstAndLast1(Matrix all_ones)
{
  Matrix FirstAndLast1;
  vector<int> tuples;

  for(size_t i(0);i<all_ones.size();i++)
  {
    int first(0);
    int last(0);
    
    first = all_ones[i][0];
    last = all_ones[i].back();
    tuples.push_back(first);
    tuples.push_back(last);
    FirstAndLast1.insert(FirstAndLast1.end(),tuples);
    tuples.clear();
  } 
  // test_display(FirstAndLast1);
  return FirstAndLast1;
}

void modification(Carte& carte, Matrix ones)
{

  for(size_t row(0);row<carte.size();row++)
  {
    for(int col(ones[row].front()); col<ones[row].back();col++)
    {
      carte[row][col] = 1;
    }
  }
  // affiche(carte);
}

bool verifie_et_modifie(Carte& carte)
{
  // Verification
  bool bool_binaire;
  bool_binaire = binaire(carte);
  Matrix FirstAndLast1s;

  if(bool_binaire==false)
  {
    cout << "Votre carte du terrain ne contient pas que des 0 et des 1." << endl;
    return false;
  }
  else
  {
    Matrix all_ones;
    all_ones = mapOnes(carte);
    FirstAndLast1s = mapFirstAndLast1(all_ones);
    modification(carte, FirstAndLast1s);
    return true;
  }
}

double longueur_cloture(Carte const& carte, double echelle = 2.5)
{
  Matrix FirstAndLast1s;
  Matrix all_ones;

  double totalLength(0.0);
  int n_rows(carte.size());
  int len_top(0);
  int len_bottom(0);

  all_ones = mapOnes(carte);
  FirstAndLast1s = mapFirstAndLast1(all_ones);

  len_top = FirstAndLast1s[0][1]+1 - FirstAndLast1s[0][0];
  len_bottom = FirstAndLast1s.back()[1]+1 - FirstAndLast1s.back()[0];

  int prev_left(0);
  int prev_right(0);
  bool init(true);
  int sum(0);
  int left(0);
  int right(0);

  for(auto i : FirstAndLast1s)
  {
      if(init==true)
      {
            prev_left = i[0];
            prev_right = i[1];
            init = false;
      }
      else
      {
            left = i[0] - prev_left;
            right = i[1] - prev_right;

            if(left<0)
            {
              left = left *-1;
            }

            if(right<0)
            {
              right = right *-1;
            }
      }

      sum = sum + right + left;
      prev_left = i[0];
      prev_right = i[1];
  }

  totalLength = 2 * n_rows;
  totalLength = totalLength + sum;
  totalLength = totalLength + len_top;
  totalLength = totalLength + len_bottom;
  totalLength = totalLength * echelle;
  return totalLength;
}

/*           cout << "Votre carte du terrain n'est pas convexe par lignes :" << endl;
          cout << "bord extérieur entrant trouvé en position [";
          cout << "][";
          cout << "]" << endl;
 */

void ajoute_unique(vector<int>& ensemble, int valeur)
{

}


bool convexite_lignes(Carte& carte, vector<int> const& labels_bords)
{
  return true;
}


bool convexite_lignes(Carte& carte)
{
  return true;
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  Carte carte = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0},
    {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
  };

  cout << "Carte au départ :" << endl;
  affiche(carte);
  if (verifie_et_modifie(carte)) {
    cout << "Carte après modification :" << endl;
    affiche(carte);
    cout << "Il vous faut " << longueur_cloture(carte)
         << " mètres de clôture pour votre terrain."
         << endl;
  }

  return 0;
}
