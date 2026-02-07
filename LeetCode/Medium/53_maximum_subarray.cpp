#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        int curr = nums[0];
        int max_sum = curr;
        for (int i = 1; i < nums.size(); i++)
        {
            curr = max(nums[i], curr + nums[i]);
            max_sum = max(max_sum, curr);
        }
        return max_sum;
    }
};