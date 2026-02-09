#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int tank = 0, curr = 0, start = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            int gasUsed = gas[i] - cost[i];
            tank += gasUsed;
            curr += gasUsed;
            if (curr < 0)
            {
                start = i + 1;
                curr = 0;
            }
        }
        return tank >= 0 ? start : -1;
    }
};