#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int minRefuelStops(int target, int startFuel,
                       vector<vector<int>> &stations)
    {
        priority_queue<int> pq;
        int stops = 0;
        int fuelLeft = startFuel;
        int prevStop = 0;
        for (vector<int> station : stations)
        {
            fuelLeft -= (station[0] - prevStop);
            while (fuelLeft < 0)
            {
                if (pq.empty())
                    return -1;
                fuelLeft += pq.top();
                stops++;
                pq.pop();
            }
            pq.push(station[1]);
            prevStop = station[0];
        }
        fuelLeft -= (target - prevStop);
        while (fuelLeft < 0)
        {
            if (pq.empty())
                return -1;
            fuelLeft += pq.top();
            stops++;
            pq.pop();
        }
        return stops;
    }
};