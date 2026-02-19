#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void zero(vector<vector<int>> &matrix, vector<int> idx1, vector<int> idx2)
    {
        for (int j = 0; j < idx1.size(); j++)
        {
            int x = idx1[j], y = idx2[j];
            for (int i = 0; i < matrix.size(); i++)
            {
                matrix[i][y] = 0;
            }
            for (int i = 0; i < matrix[x].size(); i++)
            {
                matrix[x][i] = 0;
            }
        }
    }
    void setZeroes(vector<vector<int>> &matrix)
    {
        vector<int> idx1, idx2;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    idx1.push_back(i);
                    idx2.push_back(j);
                }
            }
        }
        zero(matrix, idx1, idx2);
    }
};