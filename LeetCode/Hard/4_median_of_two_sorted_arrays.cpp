#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
         int n = nums1.size();
        int m = nums2.size();
        if (n > m)
            return findMedianSortedArrays(nums2, nums1);
        int l = 0;
        int u = n;

        while (l <= u) {
            int partitionX = l + (u - l) / 2;
            int partitionY = (n + m + 1) / 2 - partitionX;

            int leftMaxX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int leftMaxY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int rightMinX = (partitionX == n) ? INT_MAX : nums1[partitionX];
            int rightMinY = (partitionY == m) ? INT_MAX : nums2[partitionY];

            if (leftMaxX <= rightMinY && leftMaxY <= rightMinX) {
                if ((n + m) % 2 == 0)
                    return (max(leftMaxX, leftMaxY) +
                            min(rightMinX, rightMinY)) /
                           2.0;
                else {
                    return max(leftMaxX, leftMaxY);
                }
            } else if (leftMaxX > rightMinY)
                u = partitionX - 1;
            else {
                l = partitionX + 1;
            }
        }
        return 0.0;
    }
};