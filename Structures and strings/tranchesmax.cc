#include <iostream>
#include <vector>
using namespace std;

// TESTING
/* vector<vector<int>> table(
{   {0,0,5,0,1  },
    {2,0,1,3,0  },
    {3,1,0,2,0  },
    {1,0,1,0,2  } }
); */


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
    int biggestSum_index(0);
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


int main()
{
    //vector<int> v({30,100, 0,100,40,0,0,40,50});

    vector<vector<int>> table(
    {   {0,1,2,3,42,0,100,50 },
        {4,5,6,0,0,100,50  },
        {7,8,0,0,100,40  },
        {100,1,0,100,40 } }
    );

    vector<size_t> final_max_st;


    final_max_st = lignes_max(table);

    for(auto i : final_max_st)
    {
        cout<<i;
    }
    


}