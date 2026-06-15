#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,bool>map;

        for(char ch:word){
            map[ch]=true;
        }
        int c=0;
        for(auto &p:map){
            char ch=p.first;
            if(isupper(ch)&&map.count(tolower(ch)))c++;
        }
        return c;
    }
};