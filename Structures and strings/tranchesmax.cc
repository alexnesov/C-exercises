#include <iostream>
#include <vector>
using namespace std;


int somme_consecutifs_max(vector<int> v)
{
    int sum(0);
    int biggestSum(0);
    int previous_temp(0);
    for(auto i : v)
    {
        
        if(i!=0)
        {
            sum = sum +  i;
            if(sum>biggestSum)
            {
                biggestSum = sum;
            }
            
        }

        if(i==0)
        {
            if(sum>biggestSum)
            {
                biggestSum = sum;
            }
            sum = 0;
        }

    }

    previous_temp = 0;
    return biggestSum;
}

vector<size_t> lignes_max(vector<vector<int>> v)
{
    vector<size_t> lignes_max_vec;
    int previous_biggestSum(0);
    int biggestSum_line(0);
    int biggestSum_allLines(0);

    size_t iter;


    for(size_t i(0); i<v.size();i++)
    {
        vector<int> line = v[i];

        for(auto i : line)
        {
            cout << i;
        }
        cout << endl;
        biggestSum_line = somme_consecutifs_max(line);
        
        if(biggestSum_line==biggestSum_allLines)
        {
            lignes_max_vec.push_back(i);
        }

        if(biggestSum_line>biggestSum_allLines)
        {
            biggestSum_allLines = biggestSum_line;
            lignes_max_vec.clear();
            lignes_max_vec.push_back(i);
        }

        cout << "Line: " << i << " BiggestSum_line: " << biggestSum_line << endl;
        cout << "All: " << i << " biggestSum_allLines: " << biggestSum_allLines << endl;
            
    }

    previous_biggestSum = biggestSum_line;

    return lignes_max_vec;
}

vector<vector<int>> tranches_max(vector<vector<int>> v)
{
    vector<vector<int>> tab_final;
    vector<size_t> biggestSum_indices;

    biggestSum_indices = lignes_max(v);
    cout << endl;

    for(int i : biggestSum_indices)
    {
        tab_final.insert(tab_final.end(),v[i]);
    }
    cout << endl;


    return tab_final;
}

int main()
{
    //vector<int> v({30,100, 0,100,40,0,0,40,50});
    vector<vector<int>> tab_final;

    vector<vector<int>> table(
    {   {0,1,2,3,42,0,0,0 },
        {4,5,6,0,200,100,50  },
        {7,8,200,0,100,40  },
        {100,1,0,100,40 } }
    );


    tab_final = tranches_max(table);

    cout << "tab_final: " << endl;

    for(auto i : tab_final)
        {
            for(auto j : i)
            {
                cout << j;
            }
        cout << endl;
        }



}