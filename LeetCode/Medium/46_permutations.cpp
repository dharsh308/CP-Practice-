#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void ways(vector<vector<int>> &p, int idx, vector<int> &nums)
    {
        if (idx == nums.size() - 1)
        {
            vector<int> pp;
            for (int x : nums)
                pp.push_back(x);
            p.push_back(pp);
        }
        for (int i = idx; i < nums.size(); i++)
        {
            swap(nums[i], nums[idx]);
            ways(p, idx + 1, nums);
            swap(nums[i], nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> p;
        ways(p, 0, nums);
        return p;
    }
};