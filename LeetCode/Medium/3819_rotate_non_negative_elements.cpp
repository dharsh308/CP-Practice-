#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> rotateElements(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> v;
        vector<int> v1;
        for (int i : nums)
        {
            if (i >= 0)
                v.push_back(i);
        }
        int n1 = v.size();
        if (n1 == 0)
            return nums;
        k = k % n1;
        for (int i = 0; i < n1; i++)
        {
            v1.push_back(v[(i + k) % n1]);
        }
        int idx = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] >= 0)
            {
                nums[i] = v1[idx++];
            }
        }
        return nums;
    }
};