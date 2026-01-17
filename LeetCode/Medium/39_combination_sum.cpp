#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

void backtrack(int start,vector<int> &candidates,int target,vector<vector<int>>& res,vector<int>combination)
    {
        int n=candidates.size();
        if(target==0){
            res.push_back(combination);
            return;
        }
        if(target<0)return;

        for(int i=start;i<n;i++){
            combination.push_back(candidates[i]);
            backtrack(i,candidates,target-candidates[i],res,combination);
            combination.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int>path;
        backtrack(0,candidates,target,res,path);
        return res;
    }