#include <iostream>
#include <vector>
#include<queue>
using namespace std;

class RideSharingSystem
{
public:
    queue<int> rider;
    queue<int> driver;
    RideSharingSystem() {}

    void addRider(int riderId) { rider.push(riderId); }

    void addDriver(int driverId) { driver.push(driverId); }

    vector<int> matchDriverWithRider()
    {
        vector<int> result;
        if (driver.empty() || rider.empty())
            return {-1, -1};
        int d = driver.front();
        driver.pop();
        int r = rider.front();
        rider.pop();
        result.push_back(d);
        result.push_back(r);
        return result;
    }

    void cancelRider(int riderId)
    {
        queue<int> cancel;
        while (!rider.empty())
        {
            if (rider.front() == riderId)
            {
                rider.pop();
                continue;
            }
            int x = rider.front();
            rider.pop();
            cancel.push(x);
        }
        while (!cancel.empty())
        {
            int y = cancel.front();
            cancel.pop();
            rider.push(y);
        }
    }
};
