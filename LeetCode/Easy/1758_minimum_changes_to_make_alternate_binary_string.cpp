#include<iostream>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int d=0,c=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]!=(i%2==0?'0':'1'))d++;
            if(s[i]!=(i%2==0?'1':'0'))c++;
        }
        return min(c,d);
    }
};