#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        vector<pair<int, int>> freqVec;
        for (auto& [num, count] : freq) {
            freqVec.push_back({count, num});
        }
        sort(freqVec.rbegin(), freqVec.rend());

        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(freqVec[i].second);
        }
        return result;
    }
};