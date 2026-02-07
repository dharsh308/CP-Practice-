#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        set<int> s;
        for (int i : nums)
        {
            s.insert(i);
        }
        int maxLen = 1;
        for (int i : s)
        {
            if (!s.count(i - 1))
            {
                int len = 1;
                while (s.count(i + len))
                {
                    len++;
                }
                maxLen = max(len, maxLen);
            }
        }
        return maxLen;
    }
};