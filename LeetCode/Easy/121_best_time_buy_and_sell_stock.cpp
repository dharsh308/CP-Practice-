#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minPrice = INT_MAX;
        int maxProfit = INT_MIN;
        for (int i : prices)
        {
            minPrice = min(minPrice, i);
            maxProfit = max(maxProfit, i - minPrice);
        }
        return maxProfit;
    }
};