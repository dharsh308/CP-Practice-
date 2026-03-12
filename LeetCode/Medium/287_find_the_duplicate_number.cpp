#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int a:nums){
            freq[a]++;
            if(freq[a]>1){
                return a;
            }
        }
        return -1;
    }
};