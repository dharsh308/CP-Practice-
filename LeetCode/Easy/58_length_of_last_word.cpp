#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        string ss;
        vector<string> s1;
        for (char c : s)
        {
            if (c == ' ')
            {
                s1.push_back(ss);
                ss = "";
                continue;
            }
            ss += c;
        }
        s1.push_back(ss);
        for (int i = s1.size() - 1; i >= 0; i--)
        {
            if (s1[i].size() > 0)
            {
                return s1[i].size();
            }
        }
        return -1;
    }
};
