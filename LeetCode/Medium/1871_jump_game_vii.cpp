#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<int> reachable(n, false);
        reachable[0] = true;
        int reached=0;

        for(int i=0;i<n;i++){
            if(!reachable[i])continue;
            int begin=max(i+minJump,reached+1);
            int end=min(i+maxJump,n-1);

            for(int j=begin;j<=end;j++){
                if(s[j]=='0')reachable[j]=true;
            }
            reached=end;
        }
        return reachable[n - 1];
    }
};