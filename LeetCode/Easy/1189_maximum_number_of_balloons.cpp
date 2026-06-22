#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>map;
        for(char ch:text){
            map[ch]++;
        }
        string balloon="balloon";
        unordered_map<char,int>freq;
        for(char ch:balloon){
            freq[ch]++;
        }
        int instances=INT_MAX;
        for(auto &p:freq){
            int req=p.second;
            char ch=p.first;
            instances=min(instances,map[ch]/req);
        }
        return instances;
    }
};