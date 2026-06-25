#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
int unique(int n,vector<int>&dp){
    int ans=0;
    if(n<=1)return 1;
    if(dp[n]!=-1)return dp[n];

    for(int i=1;i<=n;i++){
        ans+=unique(i-1,dp)*unique(n-i,dp);
    }
    return dp[n]=ans;
}
    int numTrees(int n) {
        vector<int>dp(n+1,-1);
        return unique(n,dp);
    }
};