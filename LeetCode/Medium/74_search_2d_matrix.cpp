#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
int search(vector<vector<int>>&matrix,int m,int n,int x){
    for(int i=0;i<m;i++)
   {
    int left=0,right=n-1;
     while(left<=right){
        int mid=left+(right-left)/2;
        if(x==matrix[i][mid]){
            return 1;
        }
        if(x<matrix[i][mid]){
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }}
    return 0;
}
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix[0].size();
        int m=matrix.size();
        if(n==0||m==0){
            return false;
        }
        return search(matrix,m,n,target);
    }
};