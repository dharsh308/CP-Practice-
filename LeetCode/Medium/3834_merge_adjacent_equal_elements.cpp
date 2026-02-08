#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<long long> mergeAdjacent(vector<int> &nums)
    {
        vector<long long> res;
        for (int i : nums)
        {
            long long curr = i;
            while (!res.empty() && res.back() == curr)
            {
                curr += res.back();
                res.pop_back();
            }
            res.push_back(curr);
        }
        return res;
    }
};