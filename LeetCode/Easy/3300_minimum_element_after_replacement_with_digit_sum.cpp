#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minElement(vector<int>& nums) {
        int minSum=INT_MAX;
        for(int i:nums){
            int s=0;
            while(i>0){
                int d=i%10;
                s+=d;
                i/=10;
            }
            minSum=min(minSum,s);
        }
        return minSum;
    }
};