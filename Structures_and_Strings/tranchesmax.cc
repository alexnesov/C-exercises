#include <iostream>
#include <vector>
using namespace std;


vector<vector<int>> table(
{   {0,0,5,0,1  },
    {2,0,1,3,0  },
    {3,1,0,2,0  },
    {1,0,1,0,2  } }
);


int somme_consecutifs_max(vector<int> v)
{
    int sum(0);
    int biggestSum(0);
    
    int previous_temp(0);

    for(auto i : v)
    {
        
    sum = previous_temp + i;

    cout << endl;
    cout << "I°: " << i << endl;
    cout << "SUM: " << sum << endl;
    cout << "PREVIOUS_TEMP: " << previous_temp << endl;
    cout << "BIGGESTSUM: " << biggestSum << endl;
    
        if( (i==0) )
        {
            if(sum > biggestSum)
            {
                biggestSum = sum;
            }

            sum = 0;

        }

        if (sum > biggestSum)
        {
            biggestSum = sum;
        }
        
    previous_temp = i;

    }

    return biggestSum;
}


int main()
{
    int biggestSum_final;
    vector<int> v({1,0,3,2,0});

    cout << "INITIAL VECTOR: " << endl;
    for(auto j : v)
    {
        cout << j;
    }

    cout << endl;

    biggestSum_final = somme_consecutifs_max(v);

    cout << biggestSum_final << endl;
    
}