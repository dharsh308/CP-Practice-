#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void parenthesis(vector<string>& res, int n, string s, int o, int c) {
        if (s.size() == 2 * n) {
            res.push_back(s);
            return;
        }
        if (o < n) {
            parenthesis(res, n, s + '(', o + 1, c);
        }
        if (c < o) {
            parenthesis(res, n, s + ')', o, c + 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;
        parenthesis(res, n, s, 0, 0);
        return res;
    }
};