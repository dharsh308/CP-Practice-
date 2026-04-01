#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(s.size()<=numRows||numRows==1)return s;

        vector<string>rows(numRows);
        bool isDown=false;
        int idx=0;

        for(char ch:s){
            rows[idx]+=ch;
            if(idx==0||idx==numRows-1)isDown=!isDown;
            idx+=isDown?1:-1;
        }
        string res;
        for(string i:rows){
            res+=i;
        }
        return res;
    }
};