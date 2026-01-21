#include <iostream>
#include <vector>
#include<string>
using namespace std;

class Solution
{
public:
    int totalWays(string s, vector<int> &ways, int idx)
    {
        if (idx == s.size())
            return 1;
        if (s[idx] == '0')
            return 0;
        if (ways[idx] != -1)
            return ways[idx];
        int first = totalWays(s, ways, idx + 1);
        int second = 0;
        if (idx + 1 < s.length())
        {
            string s1 = s.substr(idx, 2);
            int remValue = stoi(s1);
            if (remValue <= 26)
                second = totalWays(s, ways, idx + 2);
        }
        return ways[idx] = first + second;
    }
    int numDecodings(string s)
    {
        vector<int> ways(s.size() + 1, -1);
        return totalWays(s, ways, 0);
    }
};