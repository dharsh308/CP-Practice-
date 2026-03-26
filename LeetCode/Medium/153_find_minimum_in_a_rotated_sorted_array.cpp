#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size() - 1;

        int l = 0, u = n;
        while (l <= u) {
            int mid = l + (u - l) / 2;

            if (nums[mid] > nums[n])
                l = mid + 1;
            else {
                u = mid - 1;
            }
        }
        return nums[l];
    }
};