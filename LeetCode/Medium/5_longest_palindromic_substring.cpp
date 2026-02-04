#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        string palindrome = "";
        int maxLen = 0;

        // odd palindrome
        for (int mid = 0; mid < n; mid++)
        {
            int l = mid - 1, r = mid + 1;
            int currLen = 1;
            while (l >= 0 && r < n && (s[l] == s[r]))
            {
                l--;
                r++;
                currLen += 2;
            }
            if (maxLen < currLen)
            {
                palindrome = s.substr(l + 1, r - l - 1);
                maxLen = currLen;
            }
        }

        // even palindrome
        for (int mid = 0; mid < n; mid++)
        {
            int i = mid;
            int j = mid + 1;
            int currLen = 1;
            while (i >= 0 && j < n && s[i] == s[j])
            {
                i--;
                j++;
                currLen += 2;
            }
            if (maxLen < currLen)
            {
                palindrome = s.substr(i + 1, j - i - 1);
                maxLen = currLen;
            }
        }
        return palindrome;
    }
};