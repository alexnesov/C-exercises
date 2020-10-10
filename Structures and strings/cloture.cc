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
  bool true_false(true);

  for(auto l : carte)
  { 
    for(auto i : l)
        {
          if(i!=0 && i!=1)
          {   
              true_false = false;
          }
        }
    }
  return true_false;

  } // For loop

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
/*   for(auto i : empty_vec_index)
  {
    cout << "EMPTY: " << i << endl;
  } */

  for(size_t l(0);l<carte.size();l++) // Iterate over rows
  {
    if(find(empty_vec_index.begin(), empty_vec_index.end(),l) != empty_vec_index.end())
    {
      continue;
    }

    for(size_t i(all_difs[l].front()); i < all_difs[l].back(); ++i) // Iterate over columns
    {
      carte[l][i] = 1;
    } 
  }

} 

vector<vector<int>> all_difs;

bool verifie_et_modifie(Carte& carte)
{
  vector<int> indices;
  bool init(true);
  int vec_col(carte[0].size());
  int vec_line(carte.size());
  int vec_colconst = vec_col;
  bool test(true);
  
/*   cout << "N° cols: " << vec_col << endl;
  cout << "N° lines: " << vec_line << endl;
  cout << "vec_colconst: " << vec_colconst << endl;
  cout << endl; */
  
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
       int col_pos(0);
      
      for(auto i : v)
        { ////// Second loop
            int prev(0);
          
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
          // cout << i;                                    // REPR_001
        } ////// Second loop

      all_difs.insert(all_difs.end(),indices);
      //re-initilizations
      vec_line = carte[0].size();
      vec_col = carte[0].size();
      indices.clear();
      col_pos = 0;
      init = true;
      // cout << endl;                                     // REPR_001
    } ///// First loop

    replace_lakes(carte=carte, all_difs=all_difs);


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

#include <algorithm>    // std::reverse

double longueur_cloture(Carte const& carte, double echelle = 2.5)
{
  int index(0);
  double vec_line(carte.size());

  vector<double> tup;
  vector<double> reversed;
  vector<vector<double>> all_tups;

  for(auto line : carte)
  {
    // Find index of first one
    // Not-rev
    for(auto col : line)
    {  
      if(col==1)
      {
        tup.push_back(index);
        break;
      }
      index++;
    }
    index=0;

    // Find index of last one
    // Rev
    reverse(line.begin(),line.end());

    for(auto col : line)
    {
      if(col==1)
      {
        tup.push_back(index);
        break;
      }
      index++;
    }

    index=0;
    all_tups.insert(all_tups.end(),tup);
    tup.clear();

  } // LOOP

  double prev_left(0.0);
  double prev_right(0.0);
  bool init(true);
  double sum(0.0);
  double left(0.0);
  double right(0.0);

  //cout << endl;
  for(auto i : all_tups)
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

  double length(0.0);
  int vec_col(carte[0].size());

  double top_carte(0.0);
  double bottom_carte(0.0);

  for(auto top:carte[0])
  {
    if(top==1)
    {
      top_carte++;
    }
  }

  for(auto bottom:carte.back())
  {
    if(bottom==1)
    {
      bottom_carte++;
    }
  }


  length = 0.00+((vec_line * 2 + sum + top_carte + bottom_carte)*2.5);
  return length;
} 


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

/*   Carte carte = {
      {1,1,1,1,0,0,0,0},
      {0,0,1,0,1,0,0,0},
      {1,1,0,1,0,0,0,0},
      {1,1,1,1,1,1,0,0},
      {0,0,0,0,1,0,0,1}
      }; */
/* 
      Carte carte = {
      {0,5,1,1,0},
      {0,1,0,1,0},
      {0,1,1,1,0}
      }; */

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
