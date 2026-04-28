#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> v;
        for (auto& pair : grid) {
            for (int k : pair) {
                v.push_back(k);
            }
        }
        int res = 0;
        sort(v.begin(), v.end());
        int mid = v[(v.size() / 2)];
        for (int i :v) {
            int rem = abs(i- mid);
            int d = 0;
            if (rem % x != 0)
                return -1;
            res += rem / x;
        }

        return res;
    }
};