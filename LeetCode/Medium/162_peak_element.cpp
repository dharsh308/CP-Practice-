#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int peak = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            if (peak < nums[i])
            {
                peak = nums[i];
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (peak == nums[i])
            {
                return i;
            }
        }
        return 0;
    }
};