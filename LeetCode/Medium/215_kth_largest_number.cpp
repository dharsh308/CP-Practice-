#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int> pq;
        for (int i : nums)
            pq.push(i);
        int kth_largest = -1;
        while (k-- > 0)
        {
            kth_largest = pq.top();
            pq.pop();
        }

        return kth_largest;
    }
};