#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int loot(vector<int> &nums, vector<int> &dp, int idx, int end)
    {
        if (idx > end)
            return 0;
        if (dp[idx] != -1)
            return dp[idx];
        int steal = nums[idx] + loot(nums, dp, idx + 2, end);
        int skip = loot(nums, dp, idx + 1, end);
        return dp[idx] = max(steal, skip);
    }
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max(nums[0], nums[1]);
        vector<int> dp(nums.size(), -1);
        vector<int> dp2(nums.size(), -1);

        int c1 = loot(nums, dp, 0, nums.size() - 2);

        int c2 = loot(nums, dp2, 1, nums.size() - 1);
        return max(c1, c2);
    }
};