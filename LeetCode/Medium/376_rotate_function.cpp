#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int maxVal = INT_MIN;
        int n = nums.size();
        if (n < 2)
            return 0;
        int sum = 0, f;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            f += (i * nums[i]);
        }
        maxVal = max(maxVal, f);
        for (int j = 1; j < n; j++) {
            f = f + sum - (n * nums[n - j]);
            maxVal = max(maxVal, f);
        }
        return maxVal;
    }
};