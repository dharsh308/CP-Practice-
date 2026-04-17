#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string s;
        vector<int> key = {1000, 900, 500, 400, 100, 90, 50,
                           40,   10,  9,   5,   4,   1};
        vector<string> value = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                                "XL", "X",  "IX", "V",  "IV", "I"};
        for (int i = 0; i < key.size(); i++) {
            while (num >= key[i]) {
                s += value[i];
                num = num - key[i];
            }
        }
        return s;
    }
};