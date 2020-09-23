#include <iostream>
using namespace std;

int annee;



int demander_annee()
{
    cout << "Entrez une annee (1583-4000) : 2006" << endl;
    do{
    cin >> annee;
    }while((annee<1583) || (annee>4000) );

    return annee;
}

void affiche_date(int annee,int nb_jours)
{

    cout << "Date de Paques en " << annee << ":" << endl;

}

int date_Paques(int annee)
{
    int siecle;
    int p;
    int q;
    int M;
    int N;
    int d;
    int e;

    siecle = annee/100;
    p = (13 + 8 * siecle)/25;
    q = siecle/4;
    M = (15 - p + siecle - q)%30;
    N = (4 + siecle - q)%7;
    d = (M + 19*(annee%19))%30;
    e = (2 * (annee % 4) + 4 * (annee % 7) + 6 * d + N) % 7;
    
    return e;

}

int main()
{
    int annee;

    demander_annee();
    date_Paques(annee);
    affiche_date(annee, nb_jours);
}