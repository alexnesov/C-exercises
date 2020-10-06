#include <iostream>

using std::cout;

int
main()
{
    int i;
    char c;
    for (i=1, c='a'; c < 'z'; ++i, ++c) {
	cout << "The " << i << "'th character is " << c << '\n';
    }

}