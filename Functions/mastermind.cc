#include <iostream>
#include <ctime>

// pour les nombres aléatoires
#include <random>
#include <cstring> // strlen

using namespace std;

// ======================================================================
// Couleur au hasard
std::uniform_int_distribution<int> distribution;
std::default_random_engine generateur(time(NULL)); /* NOT using std::random_device since not
                                                    * all compilers seems to support it :-( */

char tirer_couleur()
{
  static const char* const couleurs = ".RGBCYM";
  static const int nb = strlen(couleurs) - 1;

  return couleurs[distribution(generateur,
                               std::uniform_int_distribution<int>::param_type {0, nb})];
}

// ======================================================================
char poser_question()
{
  char lu(' ');
  cout << "Entrez une couleur : ";
  cin >> lu;
  return lu;
}

// ---- prototype -------------------------------------------------------
bool couleur_valide(char c);

// ======================================================================
char lire_couleur()
{
  char lu(poser_question());
  while (not couleur_valide(lu)) {
    cout << "'" << lu << "' n'est pas une couleur valide." << endl;
    cout << "Les couleurs possibles sont : ., R, G, B, C, Y ou M." << endl;
    lu = poser_question();
  }
  return lu;
}

// ======================================================================
void afficher_couleurs(char c1, char c2, char c3, char c4)
{
  cout << ' ' << c1 << ' ' << c2 << ' ' << c3 << ' ' << c4;
}

// ======================================================================
void afficher(int nb, char c)
{
  while (nb-- > 0) {
    cout << c;
  }
}

// ---- prototype -------------------------------------------------------
void afficher_reponses(char c1, char c2, char c3, char c4,
                       char r1, char r2, char r3, char r4);

// ======================================================================
void afficher_coup(char c1, char c2, char c3, char c4,
                   char r1, char r2, char r3, char r4)
{
  afficher_couleurs(c1, c2, c3, c4);
  cout << " : ";
  afficher_reponses(c1, c2, c3, c4,
                    r1, r2, r3, r4);
  cout << endl;
}

// ======================================================================
void message_gagne(int nb_coups)
{
  cout << "Bravo ! Vous avez trouvé en " << nb_coups << " coups." << endl;
}

// ======================================================================
void message_perdu(char c1, char c2, char c3, char c4)
{
  cout << "Perdu :-(" << endl;
  cout << "La bonne combinaison était : ";
  afficher_couleurs(c1, c2, c3, c4);
  cout << endl;
}

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/

// ======================================================================
bool couleur_valide(char c)
{
  if ((c == 'R') || (c == 'G') || (c == 'B') || (c == 'C') || (c == 'Y') || (c == 'M') || (c == '.'))
  {
    return true;
  }
  else
  {
    return false;
  }
}

// ======================================================================
bool verifier(char c, char& r, int& score)
{
  char x = 'x';

  if(c==r)
  {
    // marquer couleurs
    score++;
    r = x;
    return true;
  }
  else
  {
    return false;
  }



}

// ======================================================================
void apparier(char c, char& r1, char& r2, char& r3, int& nb)
{
  bool verif1;
  bool verif2;
  bool verif3;

  char x = 'x';

  verif1 = verifier(c,r1,nb);
  verif2 = verifier(c, r2, nb);
  verif3 = verifier(c, r3, nb);

  if(verif1)
  {
    nb++;
    r1 = x;
  }
  else if(verif2)
  {
    nb++;
    r2 = x;
  }
  else if(verif3)
  {
    nb++;
    r3 = x;
  }

}

// ======================================================================
void afficher_reponses(char c1, char c2, char c3, char c4,
                       char r1, char r2, char r3, char r4)
{
  bool verif_c1;
  bool verif_c2;
  bool verif_c3;
  bool verif_c4;
  int score;  // verifier
  int nb;     // apparier
  char c;

  verif_c1 = verifier(c1, r1, score);
  verif_c2 = verifier(c2, r2, score);
  verif_c3 = verifier(c3, r3, score);
  verif_c4 = verifier(c4, r4, score);
  
  // # 
  char hash = '#';
  afficher(score, c=hash);

  // + 
  // pour chacune des couleurs proposees qui n'etaient pas bien placees,
  // chercher a l'aide de la fonction apparier si elle s'apparie avec un des trois autres couleurs
  char plus = '+';

  if(verif_c1!=true)
  {
    apparier(c1, r2, r3, r4, nb);
  }
  else if(verif_c2!=true)
  {
    apparier(c2, r1, r3, r4, nb);
  }
  else if(verif_c3!=true)
  {
    apparier(c3, r1, r2, r4, nb);
  }
  else if(verif_c4)
  {
    apparier(c4, r1, r2, r3, nb);
  }


  afficher(nb, c=plus);

  // -
  char dash = '-';
  afficher(nb=(4-nb-score),dash);

  cout << endl;
/*   cout << "r1 : " << r1 << endl;
  cout << "r2 : " << r2 << endl;
  cout << "r3 : " << r3 << endl;
  cout << "r4 : " << r4 << endl;
 */


  // re-init
  score=0;
  nb=0;
}

// ======================================================================
bool gagne(char c1, char c2, char c3, char c4,
           char r1, char r2, char r3, char r4)
{

  if( (c1==r1) && (c2==r2) && (c3==r3) && (c4==r4) )
  {
    return true;
  } 
  else
  {
    return false;
  }
}

// ======================================================================
void jouer(int coups=8)
{
  bool win(false); 
  
  int coups_init(coups);
  int coups_effectues(0);

  char c1; 
  char c2; 
  char c3; 
  char c4;

  char r1; 
  char r2; 
  char r3; 
  char r4;

  r1 = tirer_couleur();
  r2 = tirer_couleur();
  r3 = tirer_couleur();
  r4 = tirer_couleur();  

  //// Temporary storages
  char r1_temp;
  char r2_temp;
  char r3_temp;
  char r4_temp; 
  
  r1_temp = r1;
  r2_temp = r2;
  r3_temp = r3;
  r4_temp = r4;
  ////////////////////////

  while((win==false) && (coups>=0))
  {

  c1 = lire_couleur();
  c2 = lire_couleur();
  c3 = lire_couleur();
  c4 = lire_couleur();

/*   cout << "c1 : " << c1 << endl;
  cout << "c2 : " << c2 << endl;
  cout << "c3 : " << c3 << endl;
  cout << "c4 : " << c4 << endl; 
  cout << endl; */

  afficher_coup(c1, c2, c3, c4,
                   r1, r2, r3, r4);


  win = gagne(c1, c2, c3, c4,
          r1, r2, r3, r4);


  // Re-initilizations
  r1 = r1_temp;
  r2 = r2_temp;
  r3 = r3_temp;
  r4 = r4_temp;
  coups--;
  }

  coups_effectues = coups_init-coups;


  if(win==true)
  {
    message_gagne(coups_effectues);
  }

  if((win==false) && (coups<=0))
  {
    message_perdu(c1=r1, c2=r2, c3=r3, c4=r4);
  }

}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  jouer();
  return 0;
}
