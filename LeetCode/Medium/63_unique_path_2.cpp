#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> v(m, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            if (obstacleGrid[i][0] == 1)
                break;
            v[i][0] = 1;
        }
        for (int j = 0; j < n; j++)
        {
            if (obstacleGrid[0][j] == 1)
                break;
            v[0][j] = 1;
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j] == 0)
                {
                    v[i][j] = v[i - 1][j] + v[i][j - 1];
                }
            }
        }
        return v[m - 1][n - 1];
    }
};