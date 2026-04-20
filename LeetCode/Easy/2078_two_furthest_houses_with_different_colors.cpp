#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int maxDist = INT_MIN;
        int n = colors.size();
        for (int i = colors.size() - 1; i >= 0; i--) {
            if (colors[i] != colors[0]) {
                maxDist = max(i, maxDist);
                break;
            }
        }
        for (int j = 0; j < n; j++) {
            if (colors[j] != colors[n - 1]) {
                maxDist = max(abs(n - 1 - j), maxDist);
                break;
            }
        }
        return maxDist;
    }
};