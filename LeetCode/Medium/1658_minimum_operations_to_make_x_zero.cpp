#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = 0;
        for (int i : nums) {
            sum += i;
        }

        int target = sum - x;
        if (target == 0)
            return n;

        int l = 0, curr = 0, len = -1;
        for (int r = 0; r < n; r++) {
            curr += nums[r];

            while (l <= r && curr > target) {
                curr -= nums[l++];
            }

            if (curr == target) {
                len = max(len, r - l + 1);
            }
        }
        return len == -1 ? -1 : n - len;
    }
};