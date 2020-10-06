#include <iostream>
using namespace std;



char test(char c)
{
  return c;
}

int main()
{
  const char* name = "Cherno";
  char d;

  d = test(*name);

  cout << d << endl; 

  return 0;
}