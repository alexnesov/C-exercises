#include <iostream>
#include <vector>
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


int main(){
    ex_output_table();
}