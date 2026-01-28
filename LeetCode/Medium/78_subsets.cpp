#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinations(vector<vector<int>> &res,
                                     vector<int> &nums, int idx,
                                     vector<int> &comb)
    {
        int n = nums.size();
        if (idx == n)
        {
            res.push_back(comb);
            return res;
        };
        // skip
        combinations(res, nums, idx + 1, comb);
        // take
        comb.push_back(nums[idx]);
        combinations(res, nums, idx + 1, comb);
        comb.pop_back();
        return res;
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> v;
        vector<int> comb;
        int n = nums.size();
        return combinations(v, nums, 0, comb);
    }
};