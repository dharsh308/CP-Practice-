#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int num = 1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < num)
                continue;
            if (nums[i] == num)
                num++;
            else
            {
                return num;
            }
        }
        return num;
    }
};