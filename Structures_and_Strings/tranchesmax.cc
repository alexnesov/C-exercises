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


int main()
{
    int biggestSum_final;
    vector<int> v({6,12,3,0,11});

    // TESTING
/*     cout << "INITIAL VECTOR: " << endl;
    for(auto j : v)
    {
        cout << j;
    }

    cout << endl; */

    biggestSum_final = somme_consecutifs_max(v);
    cout << biggestSum_final << endl;
    
}