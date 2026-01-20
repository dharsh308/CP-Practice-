#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int loot(vector<int> &nums, vector<int> &store, int idx)
    {
        int n = nums.size();
        if (idx >= n)
            return 0;
        if (store[idx] != -1)
            return store[idx];
        int first = nums[idx] + loot(nums, store, idx + 2);
        int second = loot(nums, store, idx + 1);
        return store[idx] = max(first, second);
    }
    int rob(vector<int> &nums)
    {
        vector<int> store(nums.size() + 1, -1);
        return loot(nums, store, 0);
    }
};