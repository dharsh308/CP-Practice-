#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        unordered_map<char, int> map = {{'0', 0}, {'1', 1}, {'2', 2}, {'3', 3},
                                        {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7},
                                        {'8', 8}, {'9', 9}};
        int idx = 0;
        int n = s.size();
        while (idx < s.size() && isspace(s[idx]))
            idx++;
        int sign = 1;
        if (idx < n && (s[idx] == '-' || s[idx] == '+')) {
            sign = (s[idx] == '-') ? -1 : 1;
            idx++;
        }
        while (idx < s.size() && s[idx] == '0')
            idx++;
        long long res = 0;
        while (idx < n && isdigit(s[idx])) {
            int digit = s[idx] - '0';
            res = res * 10 + digit;
            if (res * sign > INT_MAX)
                return INT_MAX;
            if (res * sign < INT_MIN)
                return INT_MIN;

            idx++;
        }
        return (int)(res * sign);
    }
};