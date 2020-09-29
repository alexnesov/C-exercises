#include <iostream>
#include <vector>
using namespace std;


vector<double> tab(10);

void ex_no_spell_indices(){
    vector<int> u(7);
    vector<int> v(u);

    cout << "The table contains: " << endl;
    for(auto element : v){
        cout << element << " " << endl;
    }
}

void ex_spell_indices(){
    for(size_t i(0); i < tab.size(); ++i){
        cout << "The element " << i << " value is : " << tab[i] << endl;
    }
}

void ex_classic_iter(){

    vector<int> ages(5);

    cout << endl;
    for(size_t i(0); i < ages.size(); ++i){
        cout << "The employees age is: " << i+1 << " ? "<< endl;
        cin >> ages[i];
    }


}

vector<double> v(3, 3.14);


void test(){

for (size_t valeur(0); valeur < v.size(); ++valeur) {
  cout << v[valeur] << ", ";
}
cout << endl;
}

void test2(){

    for (auto valeur : v) {
  cout << valeur << ", ";
}
cout << endl;
}



void ex_vector_elements(){


    vector<double> v1;
    vector<double> v2(3);
    vector<double> v3({4.0});
    
    cout << endl;
    cout << v1.size() << ", " << v2.size() << ", " << v3.size() << endl;
    // Output : 0, 3, 1
    }

int main(){

    ex_vector_elements();
    cout << endl;
    cout << "Iterating thoutgh table in a traditionnal fashion: " << endl;
    //ex_classic_iter();
    cout << "\n";
    
    cout << "Ex_no_spell_indices: " << endl;
    cout << "_______________________" << endl;
    cout << "\n";
    cout << "\n";
    ex_no_spell_indices();
    
    cout << "\n";
    cout << "Ex_spell_indices: " << endl;
    cout << "_______________________" << endl;
    ex_spell_indices();

    test();
    test2();


}