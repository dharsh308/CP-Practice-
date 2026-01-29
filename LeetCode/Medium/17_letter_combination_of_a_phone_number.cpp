#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    unordered_map<char, vector<char>> phn;
    void combinations(vector<string> &comb, string s, int idx, string s1)
    {
        int n = s.size();
        if (idx == n)
        {
            comb.push_back(s1);
        }
        char key = s[idx];
        vector<char> ch = phn[key];
        for (char c : ch)
        {
            combinations(comb, s, idx + 1, s1 + c);
        }
    }
    vector<string> letterCombinations(string digits)
    {
        vector<string> comb;
        if (digits.size() == 0)
            return comb;
        phn['2'] = {'a', 'b', 'c'};
        phn['3'] = {'d', 'e', 'f'};
        phn['4'] = {'g', 'h', 'i'};
        phn['5'] = {'j', 'k', 'l'};
        phn['6'] = {'m', 'n', 'o'};
        phn['7'] = {'p', 'q', 'r', 's'};
        phn['8'] = {'t', 'u', 'v'};
        phn['9'] = {'w', 'x', 'y', 'z'};
        combinations(comb, digits, 0, "");
        return comb;
    }
};