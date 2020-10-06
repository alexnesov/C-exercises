#include <iostream>
#include <string>

int main()
{
    std::string name = std::string("Alex") + " hello!" + " test";

    //  find text in string.
    std::cout << name.find("ex") << std::endl;
    // return true or false depending on the characters are present in the string.
    // npos == illegal position.
    // traduction: return true if find is different than illegal position
    bool contains = name.find("ex") != std::string::npos;
    // In our case "ex" exists in name. HENCE, it returns true becase it's != !=
    std::cout << name << std::endl;
    std::cout << contains << std::endl;
}