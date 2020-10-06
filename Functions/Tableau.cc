#include <iostream>
#include <vector>
using namespace std;

// Un tableau est une collection de valeurs homogènes (= même type)



vector<int> tab_ages() {

    vector<int> ages(5);

    for(size_t i(0); i < ages.size(); ++i)
    {
        cout << "Age de l'employé " << i + 1 << " ? ";
        cin >> ages[i];
    }

    return  ages;
}


int main() {

vector<double> v(3);

    for (auto& x : v) {
    x = x + 1.1;
    }

    for (auto x : v) {
    cout << x << ", ";
    }

    tab_ages();
}