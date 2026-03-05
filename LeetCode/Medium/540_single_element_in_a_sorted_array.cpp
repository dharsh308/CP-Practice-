#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int i:nums){
            freq[i]++;
        }
        for(auto& [key,c]:freq){
            if(c<2){
                return key;
            }
        }
        return -1;
    }
};