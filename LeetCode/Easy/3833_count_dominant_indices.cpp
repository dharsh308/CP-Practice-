#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int dominantIndices(vector<int> &nums)
    {
        int n = nums.size();
        int c = 0;
        vector<long long> Sum(n, 0);
        Sum[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            Sum[i] = (Sum[i + 1] + nums[i]);
        }
        for (int i = 1; i < n; i++)
        {
            double Avg = Sum[i] / (n - i);
            if (nums[i - 1] > Avg)
                c++;
        }
        return c;
    }
};