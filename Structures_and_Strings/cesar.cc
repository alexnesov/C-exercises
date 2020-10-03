#include <iostream>
#include <vector>
#include <string>
using namespace std;


char decale(char c, char debut, int& decalage)
{
    char new_char;

    while(decalage<0)
    {
        decalage = decalage+26;
    }
    
    new_char = debut + (((c - debut) + decalage) % 26);
    return new_char; 
}


char code(char initialChar, int d)
{
    char dec;

    if((initialChar >= 'a') && (initialChar<='z'))
    {
        d = decale(initialChar, 'a', d);
        return d;
    }
    else if ((initialChar >='A') && (initialChar <= 'Z'))
    {
        d = decale(initialChar, 'A', d);
        return d;
    }
    else
    {
        return initialChar;
    } 

}

string code(string initialString,int d)
{

    string final_string;

    for(size_t i(0); i <= initialString.size(); i++)
    {
        char old_char;
        char new_char;


        old_char = initialString[i];
        new_char = code(old_char,d);
        final_string.push_back(new_char);
    }

    return final_string;
    
}


int main()
{
    int d;
    string final_output;

    string initialString;
    cout << "Type lag n°:" << endl;
    cin >> d;
    cout << "Type string: " << endl;
    cin >> initialString;

    final_output = code(initialString, d);
    cout << "Encoded text: " << endl;
    cout << final_output << endl;

    return 0;
}