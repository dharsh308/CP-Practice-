#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(), cost.rend());
        int totalCost = 0;
        for (int i = 0; i < cost.size(); i++) {
            if (i % 3 != 2)
                totalCost += cost[i];
        }
        return totalCost;
    }
};