#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size(), c = 0;
        vector<int> v;
        int up = 0, left = 0, down = m - 1, right = n - 1;
        while (c < m * n)
        {
            for (int i = left; i <= right; i++)
            {
                v.push_back(matrix[up][i]);
                c++;
            }
            for (int i = up + 1; i <= down; i++)
            {
                v.push_back(matrix[i][right]);
                c++;
            }
            if (up != down)
            {
                for (int i = right - 1; i >= left; i--)
                {
                    v.push_back(matrix[down][i]);
                    c++;
                }
            }
            if (left != right)
            {
                for (int i = down - 1; i > up; i--)
                {
                    v.push_back(matrix[i][left]);
                    c++;
                }
            }
            up++;
            down--;
            left++;
            right--;
        }
        return v;
    }
};