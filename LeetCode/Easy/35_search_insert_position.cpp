#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
int binarysearch(vector<int>& nums, int start, int end, int target) {
    if (start > end) return -1;
    int mid = start + (end - start) / 2;
    if (nums[mid] == target) {
        return mid;
    }
    if (nums[mid] > target) {
        return binarysearch(nums, start, mid - 1, target);
    }
    return binarysearch(nums, mid + 1, end, target);
}

int searchInsert(vector<int>& nums, int target) {
    int result = binarysearch(nums, 0, nums.size() - 1, target);
    if (result != -1) return result;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] >= target) {
            return i;
        }
    }
    return nums.size(); }
};