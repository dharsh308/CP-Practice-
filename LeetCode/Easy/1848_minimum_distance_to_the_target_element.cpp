#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int minDist=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(target==nums[i]){
                minDist=min(abs(i-start),minDist);
            }
        }
        return minDist;
    }
};