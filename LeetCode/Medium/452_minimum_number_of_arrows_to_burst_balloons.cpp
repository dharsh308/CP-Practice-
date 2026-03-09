#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        if(points.empty())return 0;
        sort(points.begin(), points.end(),
             [](const auto& a, const auto& b) {
                 return a[1] < b[1];
             });
        int arrows = 0;
        long long  range = LLONG_MIN;
         for(const auto&point:points)
         {
            if (range < point[0]) {
                range = point[1];
                arrows++;
            }
        }
        return arrows;
    }
};