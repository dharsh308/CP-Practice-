#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>res;
        for(int i:nums){
            if(i<pivot)res.push_back(i);
        }
        for(int i:nums){
            if(i==pivot)res.push_back(i);
        }
        for(int i:nums){
            if(i>pivot)res.push_back(i);
        }
        return res;
    }
};