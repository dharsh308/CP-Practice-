#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool rotation(int n) {
        unordered_map<int, int> map = {{0, 0}, {1, 1}, {2, 5}, {5, 2},
                                       {6, 9}, {8, 8}, {9, 6}};
        int x = n, res = 0, place = 1;
        while (x > 0) {
            int d = x % 10;
            if (!map.count(d))
                return false;
            res += map[d] * place;
            place *= 10;
            x /= 10;
        }
        return n != res;
    }
    int rotatedDigits(int n) {
        int k = 0;
        for (int i = 0; i <= n; i++) {
            if (rotation(i))
                k++;
        }
        return k;
    }
};