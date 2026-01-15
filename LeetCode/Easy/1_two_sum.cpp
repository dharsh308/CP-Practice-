#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> idx;
        for (int i = 0; i < nums.size(); i++) {
            int remValue = target - nums[i];
            if (idx.count(remValue))
                return {idx[remValue], i};
            idx[nums[i]] = i;
        }
        return {};
    }
};