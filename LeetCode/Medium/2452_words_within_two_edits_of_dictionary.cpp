#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool check(string s1, string s2) {
        int d = 0;
        for (int i = 0; i < min(s1.size(), s2.size()); i++) {
            if (s1[i] != s2[i])
                d++;
            if (d > 2)
                return false;
        }
        return true;
    }
    vector<string> twoEditWords(vector<string>& queries,
                                vector<string>& dictionary) {
        vector<string> res;
        for (string j: queries) {
                for (string i : dictionary) {
                    if (check(i, j) == true ) {
                        res.push_back(j);
                        break;
                        
                    }
                }
        }
        return res;
    }
};