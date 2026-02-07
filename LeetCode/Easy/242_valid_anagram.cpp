#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        string s1 = "", s2 = "";
        vector<int> freq1(26, 0), freq2(26, 0);
        for (char ch : s)
        {
            freq1[ch - 'a']++;
        }
        for (char ch : t)
        {
            freq2[ch - 'a']++;
        }
        for (int i : freq1)
        {
            s1 += to_string(i) + "";
        }
        for (int i : freq2)
        {
            s2 += to_string(i) + "";
        }
        return s1 == s2;
    }
};