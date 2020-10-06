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
        
    // TESTING
        cout << endl;
        cout << "I°: " << i << endl;
        cout << "BIGGESTSUM: " << biggestSum << endl;
        
        if(i!=0)
        {
            sum = sum +  i;
            cout << "SUM: " << sum << endl;
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

    return biggestSum;
}

vector<size_t> lignes_max(vector<vector<int>> v)
{
    vector<size_t> lignes_max_vec;
    int biggestSum_index(0);
    int previous_biggestSum(0);
    int biggestSum(0);
    size_t iter;


    for(size_t i(0); i<v.size();i++)
    {
        vector<int> line = v[i];
        biggestSum = somme_consecutifs_max(line);
        if(biggestSum>previous_biggestSum)
        {
            lignes_max_vec.clear();
            lignes_max_vec.push_back(i);
        }
    }


    return lignes_max_vec;
}


int main()
{
    //vector<int> v({30,100, 0,100,40,0,0,40,50});

    vector<vector<int>> table(
    {   {0,1,2,3,42 },
        {4,5,6,0,0  },
        {7,8,0,0,1  },
        {9,0,1,0,15 } }
    );

    vector<size_t> final_max_st;
    // TESTING
/*     cout << "INITIAL VECTOR: " << endl;
    for(auto j : v)
    {
        cout << j;
    }

    cout << endl; */


    final_max_st = lignes_max(table);

}