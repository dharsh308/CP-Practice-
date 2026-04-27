#include <iostream>
#include <vector>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

    unordered_map<int, vector<pair<int,int>>> dirs = {
        {1, {{0,-1},{0,1}}},   
        {2, {{-1,0},{1,0}}}, 
        {3, {{0,-1},{1,0}}},  
        {4, {{0,1},{1,0}}},    
        {5, {{0,-1},{-1,0}}}, 
        {6, {{0,1},{-1,0}}}    
    };

    queue<pair<int,int>> q;
    vector<vector<bool>> visited(m, vector<bool>(n,false));

    q.push({0,0});
    visited[0][0] = true;

    while (!q.empty()) {
        auto [i,j] = q.front();
        q.pop();

        if (i == m-1 && j == n-1) return true;

        int val = grid[i][j];
        for (auto [di,dj] : dirs[val]) {
            int ni = i+di, nj = j+dj;
            if (ni<0 || nj<0 || ni>=m || nj>=n) continue;

            int nextVal = grid[ni][nj];
            for (auto [ndi,ndj] : dirs[nextVal]) {
                if (ndi == -di && ndj == -dj) {
                    if (!visited[ni][nj]) {
                        visited[ni][nj] = true;
                        q.push({ni,nj});
                    }
                }
            }
        }
    }
    return false;
    }
};