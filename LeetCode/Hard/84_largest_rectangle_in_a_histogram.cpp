#include <iostream>
#include <stack>
#include<vector>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
     stack<int>s;
     int maxArea=0;
     int n=heights.size();
     for(int i=0;i<n;i++){
        while(!s.empty()&&heights[i]<heights[s.top()]){
            int idx=s.top();
            s.pop();
            int l=(s.empty()?-1:s.top());
            int r=i;
            maxArea=max(maxArea,heights[idx]*(r-l-1));
        }
        s.push(i);
     }
     while(!s.empty()){
            int idx=s.top();
            s.pop();
            int l=(s.empty()?-1:s.top());
            int r=n;
            maxArea=max(maxArea,heights[idx]*(r-l-1));
        }
     return maxArea;
    }
};