#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        vector<int> v;
        unordered_map<int, int> freq;
        for (int i : nums)
        {
            freq[i]++;
        }
        for (auto &[key, count] : freq)
        {
            if (count == 1)
                v.push_back(key);
        }
        return v;
    }
};
