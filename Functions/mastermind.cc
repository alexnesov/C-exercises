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
  static const char *const couleurs = ".RGBCYM";
  static const int nb = strlen(couleurs) - 1;

  return couleurs[distribution(generateur,
                               std::uniform_int_distribution<int>::param_type{0, nb})];
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
  while (not couleur_valide(lu))
  {
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

  while (nb-- > 0)
  {

    // existing

    cout << c; // ~
  }
}

// ---- prototype -------------------------------------------------------
void afficher_reponses(char c1, char c2, char c3, char c4,
                       char& r1, char& r2, char& r3, char& r4);

// ======================================================================
void afficher_coup(char c1, char c2, char c3, char c4,
                   char& r1, char& r2, char& r3, char& r4)
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

int score(0);

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
  char hash = '#'; // existing
  char x = 'x';

  int nb(0);

  if(c==r)
  {
    // marquer couleurs
    score++;
    nb++;
    r = x;
    return true;
  }
  else
  {
    return false;
  }

  afficher(nb, hash);
}

// ======================================================================
void apparier(char c, char& r1, char& r2, char& r3, char& r4,int& score)
{
  char plus = '+'; // well positionned
  char x = 'x';

  int nb(0);


  if(c==r1)
  {
    score++;
    nb++;
    r1 = x;
  }
  else if (c==r2)
  {
    score++;
    nb++;
    r2 = x;
  }
  else if (c==r3)
  {
    score++;
    nb++;
    r3 = x;
  }
  else if (c==r4)
  {
    score++;
    nb++;
    r4 = x;
  }
  
  afficher(nb, plus);
}

// ======================================================================
void afficher_reponses(char c1, char c2, char c3, char c4,
                       char& r1, char& r2, char& r3, char& r4)
{
  char dash = '-';
  int final_score(0);

  verifier(c1, r1, score);
  verifier(c2, r2, score);
  verifier(c3, r3, score);
  verifier(c4, r4, score);

  apparier(c1, r1, r2, r3, r4, score);
  apparier(c2, r1, r2, r3, r4, score);
  apparier(c3, r1, r2, r3, r4, score);
  apparier(c4, r1, r2, r3, r4, score);

  final_score = 4 - score;
  afficher(final_score, dash);
  cout << "Score : " << score << endl;

}

// ======================================================================
bool gagne(char c1, char c2, char c3, char c4,
           char r1, char r2, char r3, char r4)
{
  return false;
}

// ======================================================================
void jouer(int coups=8)
{
  // c = user  r = reference color, randomly generated by the program
  char c1; 
  char c2; 
  char c3; 
  char c4;
  char r0;
  char r1; 
  char r2; 
  char r3; 
  char r4;

  bool verifier_bool;
  bool win(false); 

  r0 = tirer_couleur();
  r1 = tirer_couleur();
  r2 = tirer_couleur();
  r3 = tirer_couleur();
  r4 = tirer_couleur();
 

  do
  {

    c1 = lire_couleur();
    c2 = lire_couleur();
    c3 = lire_couleur();
    c4 = lire_couleur();
    
    cout << endl;
    cout << "r1 : " << r1 << endl;
    cout << "r2 : " << r2 << endl;
    cout << "r3 : " << r3 << endl;
    cout << "r4 : " << r4 << endl;
    cout << endl;

    coups--;
    cout << "Coups restants : " << coups << endl;

    verifier_bool = verifier(c1, r1, score);

    win = gagne(c1, c2, c3, c4,
          r1, r2, r3, r4);

    afficher_coup(c1, c2, c3, c4,
                   r1, r2, r3, r4);

    // Personnal verification
    // cout << "Verification : " << verifier_bool << endl;
    cout << "r1 : " << r1 << endl;
    cout << "r2 : " << r2 << endl;
    cout << "r3 : " << r3 << endl;
    cout << "r4 : " << r4 << endl;

    cout << endl;

    cout << "c1 : " << c1 << endl;
    cout << "c2 : " << c2 << endl;
    cout << "c3 : " << c3 << endl;
    cout << "c4 : " << c4 << endl;

    // Re-initilizations

    score = 0;

  } while((win==false) && (coups>=0));


}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  jouer();
  return 0;
}
