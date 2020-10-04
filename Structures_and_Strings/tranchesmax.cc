#include <vector>
#include <iostream>
#include <string>

std::vector<std::vector<int>> table(
{   {0,1,2,0,1 },
    {0,1,1,1,0 },
    {3,0,0,0,2 },
    {1,0,2,3,0 } }
);

int iterate_over_vector(std::vector<std::vector<int>> v)
{

    int sum;
    int best_sum;

    for(auto i : v)
    {
        for(auto j : i)
        {
        std::cout << j << std::endl;
        }
    }
    return best_sum;
}

int main()
{
    iterate_over_vector(table);
    return 0;
}