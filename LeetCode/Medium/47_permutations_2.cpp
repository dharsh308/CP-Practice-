#include <iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    void combinations(vector<vector<int>>& p, vector<int>& nums, int idx,
                      set<vector<int>>& visited) {
        if (idx == nums.size() - 1) {
            vector<int> v;
            for (int i : nums)
                v.push_back(i);
            if (visited.find(v) == visited.end()) {
                p.push_back(v);
                visited.insert(v);
            }
        }

        for (int i = idx; i < nums.size(); i++) {
            swap(nums[i], nums[idx]);
            combinations(p, nums, idx + 1, visited);
            swap(nums[i], nums[idx]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> per;
        set<vector<int>> visited;
        combinations(per, nums, 0, visited);
        return per;
    }
};