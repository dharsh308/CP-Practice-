#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Solution {
public:
    int vowelConsonantScore(string s) {
        int v=0,n=s.size();
        int c=0;
        for(char i:s){
            if(i=='a'||i=='e'||i=='i'||i=='o'||i=='u'){
                v++;
            }
            if(i>='a'&&i<='z')c++;
        }
        c=c-v;
        if(c<1)return 0;
        return floor(v/c);
    }
};