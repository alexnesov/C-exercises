#include <iostream>
#include <vector>
using namespace std;

/*******************************************
 * Complétez le programme à partir d'ici.
 *******************************************/

typedef vector<vector<int>> Carte;
bool ok(true);

struct Position
{
  int i; // line
  int j; // column
};

/*   cout << "Votre carte du terrain n'est pas convexe par lignes :" << endl;
  cout << "bord extérieur entrant trouvé en position [";
  cout << "][";
  cout << "]" << endl; */

bool binaire(Carte const& carte)
{

    bool stop(false);

    for(auto l : carte)
    { 
        if(stop==true)
        {
            break;
        }
        {
            for(auto i : l)
            {
                if((i!=0) && (i!=1))
                {
                    stop = true;
                    ok = false;
                    break;
                }
            }
        }
    }
                return ok;
}

#include <algorithm>

void replace_lakes(vector<vector<int>>& carte, vector<vector<int>> all_difs)
{
  // l = line index
  // Iterate of all lines and get index for each line.
  // For every line, if n_diff >2, then all 0's between 
  // first diff and last diff transformed to 1.



  // When only ones --> Following error: "core dumped(segmentation fault)"
  // So, need to test if line full of 0 or 1. If full, then replace func. 
  // no called, otherwise func. creates troubles.

  // Check which lines don't represent water
  vector<int> empty_vec_index;
  int index_n(0);

  for(auto i : all_difs)
  {
    if(i.empty())
    {
      empty_vec_index.push_back(index_n);
    }
    index_n++;
  }

  // Print empty vec
  for(auto i : empty_vec_index)
  {
    cout << "EMPTY: " << i << endl;
  }

  for(size_t l(0);l<carte.size();l++) // Iterate over rows
  {
    if(find(empty_vec_index.begin(), empty_vec_index.end(),l) != empty_vec_index.end())
    {
      cout << endl;
      cout << "FOUND!" << endl;
      continue;
    }

    for(size_t i(all_difs[l].front()); i < all_difs[l].back(); ++i) // Iterate over columns
    {
      carte[l][i] = 1;
    } 
  }



} 

bool verifie_et_modifie(Carte& carte)
{
  vector<int> indices;
  vector<vector<int>> all_difs;
  bool init(true);
  int prev(0);
  int vec_col(carte[0].size());
  int vec_line(carte.size());
  int vec_colconst = vec_col;
  bool test(true);
  int col_pos(0);
  
  cout << "N° cols: " << vec_col << endl;
  cout << "N° lines: " << vec_line << endl;
  cout << "vec_colconst: " << vec_colconst << endl;
  cout << endl;
  
  test = binaire(carte);

    if(test==false)
    {
        cout << "Votre carte du terrain ne contient pas que des 0 et des 1." << endl;
        return false;
    }
    else
    {

      for(auto v : carte)
      { ///// First loop
      
      for(auto i : v)
        { ////// Second loop
          
            if(init==true)
            {
              prev = i;
              init = false;
            }
            else
            {
                  if(i!=prev)
                  {
                    // pushing back the column indices into vector names "indices"
                    col_pos = vec_colconst - vec_col;
                    //cout << endl;
                    //cout << "COL POS: " << col_pos;
                    indices.push_back(col_pos);
                    prev=i;
                  }
            }
          vec_col--;
          cout << i;                                    // REPR_001
        } ////// Second loop

      all_difs.insert(all_difs.end(),indices);
      //re-initilizations
      vec_line = carte[0].size();
      vec_col = carte[0].size();
      indices.clear();
      col_pos = 0;
      init = true;
      cout << endl;                                     // REPR_001
    } ///// First loop

    replace_lakes(carte=carte, all_difs=all_difs);

    // Print all_difs:
    cout << endl;
    for(auto i : all_difs)
    {
      for(auto j : i)
      {
        cout << j << ", ";
      }
      cout << endl;
    }

    return true;

  }
}

void affiche(Carte const& carte)
{
  for(auto l : carte)
  {
    for(auto c : l)
    {
      cout << c;
    }
    cout << endl;
  }
  cout << endl;
  cout << "----";
  cout << endl;
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
/*     cout << "Il vous faut " << longueur_cloture(carte)
         << " mètres de clôture pour votre terrain."
         << endl; */
  }

  return 0;
}
