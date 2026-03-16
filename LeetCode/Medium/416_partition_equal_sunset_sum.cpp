#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i : nums)
            sum += i;
        int target=sum/2;

        if (sum % 2 == 0)
        {
            vector<bool>dp(sum/2+1,false);
          dp[0]=true;
          for(int i:nums){
            for(int j=target;j>=i;j--){
                dp[j]=dp[j]||dp[j-i];
            }
        }
        return dp[target];
    }
        return false;
    }
};