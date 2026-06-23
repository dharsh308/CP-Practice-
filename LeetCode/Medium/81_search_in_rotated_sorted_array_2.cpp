#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int first = 0, last = nums.size() - 1;
        while (first <= last) {
            int mid = first + (last - first) / 2;
            if (target == nums[mid]) {
                return true;
            } else if (nums[mid] < target) {
                first = mid + 1;
            } else {
                last = mid - 1;
            }
        }
        return false;
    }
};