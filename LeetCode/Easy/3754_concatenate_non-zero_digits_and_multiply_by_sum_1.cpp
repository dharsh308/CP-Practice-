#include<iostream>
using namespace std;

class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        long long c = 1;
        while (n > 0) {
            int d = n % 10;
            if (d != 0) {
                x = d * c + x;
                c *= 10;
            }
            n /= 10;
        }
        if (x == 0)
            return 0;
        long long z = x, sum = 0;
        while (z > 0) {
            int d = z % 10;
            sum += d;
            z /= 10;
        }
        return x * sum;
    }
};