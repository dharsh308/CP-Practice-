#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> freq;
        for (int i : nums)
        {
            freq[i]++;
            if (freq[i] > (n / 2))
            {
                return i;
            }
        }
        return -1;
    }
};