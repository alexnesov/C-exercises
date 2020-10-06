#include <iostream>
using namespace std;

int const N(2);

void f(int& n)
{
  if (n <= 0) {
    cout << "Rien" << endl;
  }

  for (int s(n), i(n+1); i <= n*2; ++i) {
    s += i;
    cout << s << " = " ;
    
    for (int j(n); j < i; ++j) {
      cout << j << " + ";
    }
    
    cout << i << endl;
  }

  n = n + 2;
}

int main()
{
  int j(0);
  int n(N%2);
  int m(0);

  while (j < N) {
    cout << "Encore une autre :" << endl;
    f(n);
    cout << "-----" << endl;

    m = n + 1 - j*3;
    f(m);
    ++j;
  }

  return 0;
}
