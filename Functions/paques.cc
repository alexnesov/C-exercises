#include <iostream>
using namespace std;

int annee;

int demander_annee()
{
    
    do{
    cout << "Entrez une annee (1583-4000) : ";
    cin >> annee;
    }while((annee<1583) || (annee>4000) );
    return annee;
}

void affiche_date(int& annee,int e)
{

    if(e<=31)
    {
    cout << "Date de Paques en " << annee << " : " << e << " mars" << endl;
    }
    else if(e>=32)
    {
        e = e-31;
    cout << "Date de Paques en " << annee << " : " << e << " avril" << endl;
    }


}

int date_Paques(int& annee)
{
    int siecle;
    int p;
    int q;
    int M;
    int N;
    int d;
    int e;
    int jour;

    int temp;

    siecle = annee/100;
    p = (13 + 8 * siecle)/25;
    q = siecle/4;
    M = (15 - p + siecle - q)%30;
    N = 4 + siecle - q%7;
    d = (M + 19*(annee%19))%30;
    e = (2 * (annee % 4) + 4 * (annee % 7) + 6 * d + N) % 7;
    jour = e + d + 22;
    
    temp = (11*(M+1))%30;

    if((e==6) && ( (d==29) || ((d==28) && (temp<19) ) ) ) 
    {
        jour = jour - 7;
    }

    return jour;

}

int main()
{   
    int jour;

    demander_annee();
    jour = date_Paques(annee);
    affiche_date(annee,jour);
}