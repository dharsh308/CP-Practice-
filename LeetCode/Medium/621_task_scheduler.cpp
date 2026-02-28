#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        unordered_map<char, int> freq;
        for (char ch : tasks)
        {
            freq[ch]++;
        }
        priority_queue<int> pq;
        for (auto &entry : freq)
        {
            pq.push(entry.second);
        }
        int intervals = 0;
        while (!pq.empty())
        {
            int cycle = n + 1;
            vector<int> temp;
            int taskCount = 0;
            while (cycle > 0 && !pq.empty())
            {
                int curr = pq.top();
                pq.pop();
                if (curr > 1)
                    temp.push_back(curr - 1);
                taskCount++;
                cycle--;
            }
            for (int remaining : temp)
            {
                pq.push(remaining);
            }
            intervals += pq.empty() ? taskCount : (n + 1);
        }
        return intervals;
    }
};