#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        vector<int> R_max(n, INT_MIN);
        R_max[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            R_max[i] = max(height[i], R_max[i + 1]);
        }
        int L_max = -1;
        int maxWater = 0;
        for (int i = 0; i < n; i++)
        {
            L_max = max(height[i], L_max);
            maxWater += min(L_max, R_max[i]) - height[i];
        }
        return maxWater;
    }
};