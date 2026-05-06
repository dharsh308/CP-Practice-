#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m=boxGrid.size();
        int n=boxGrid[0].size();
        vector<vector<char>>res(n,vector<char>(m));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res[j][m-1-i]=boxGrid[i][j];
            }
        }
        for (int j = 0; j < m; j++) {          
        int empty = n - 1;                 
        for (int i = n - 1; i >= 0; i--) { 
            if (res[i][j] == '*') {
                empty = i - 1;             
            } else if (res[i][j] == '#') {
                swap(res[i][j], res[empty][j]);
                empty--;
            }
        }
    }
        return res;
    }
};