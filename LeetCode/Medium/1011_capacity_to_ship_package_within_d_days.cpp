#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValid(vector<int>& weights, int days, int capacity) {
        int currCapacity = capacity;
        for (int i = 0; i < weights.size();) {
            if (currCapacity - weights[i] >= 0) {
                currCapacity -= weights[i++];
            } else {
                days--;
                if (days == 0)
                    return false;
                currCapacity = capacity;
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = INT_MIN, u = 0;
        for (int i : weights) {
            l = max(l, i);
            u += i;
        }
        while (l <= u) {
            int mid = l + (u - l) / 2;
            if (isValid(weights, days, mid))
                u = mid - 1;
            else {
                l = mid + 1;
            }
        }
        return l;
    }
};