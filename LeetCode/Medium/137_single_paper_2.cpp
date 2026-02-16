#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        for (int i : nums)
            freq[i]++;
        for (auto &[key, count] : freq)
        {
            if (count == 1)
                return key;
        }
        return 0;
    }
};