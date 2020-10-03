#include <iostream>
#include <vector>
#include <string>

#include <typeinfo>


char decale(char c, char debut, int decalage)
{
    char new_char;

    while(decalage<0)
    {
        decalage = decalage+26;
    }
    
    new_char = debut + (((c - debut) + decalage) % 26);
    return new_char; 
}


char code(char c, int d)
{

    char decalee;

    if((c >= 'a') && (c<='z'))
    {
        decalee = decale(c, 'a', d);
        return decalee;
    }
    else if ((c >='A') && (c <= 'Z'))
    {
        decalee = decale(c, 'A', d);
        return decalee;
    }
    else
    {
        return c;
    } 

}

std::string code(std::string initialString, int d)
{

    std::string final_string="";

    for(size_t i(0); i <= initialString.size(); i++)
    {
        char old_char;
        char new_char;


        old_char = initialString[i];
        new_char = code(old_char,d);
        final_string.push_back(new_char);
    }
    std::cout << final_string << std::endl;
    final_string.pop_back();


    return final_string;
    
}

std::string decode(std::string toDecode, int d)
{
    std::string decoded;

    d = d*-1;
    decoded = code(toDecode,d);

    return decoded;
}

int main()
{
    code("Fuyez manants", 4);
    decode("Jycid qererxw", 4);
    return 0;
}