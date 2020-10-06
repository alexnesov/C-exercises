#include <iostream>
#include <vector>
#include <array>
using namespace std;

vector<vector<int>> table(
{   {0,1,2,3,42 },
    {4,5,6      },
    {7,8        },
    {9,0,1      } }
);

void ex_output_table(){
    for(auto line : table){
        for(auto element : line){
            cout << element << " ";
        }
        cout << endl;
    }


}


void ex_array(){
    array<int, 3> tab1 = {1, 2, 3};
    array<int, 3> tab2 ;

    tab2 = tab1;

}



void ex_output_table_test()
    {

        vector<vector<int>> tab_test(5, vector<int>(10,5));

        for(auto line : tab_test){
            for(auto element : line){
                cout << element << " ";
            }
            cout << "\n";


            
        }
        cout << "\n";
        cout << tab_test[1][0];
    }

void iterate_over_vector(vector<int> v){
    for(auto element : v){
        cout << element << endl;
    }
}

void a(){

    vector<int>v(5,2);

    iterate_over_vector(v);
}






int main(){
    ex_output_table();
    ex_array();
    cout << "\n";
    ex_output_table_test();
    cout << "\n";
    cout << "a: " << endl;
    a();

}