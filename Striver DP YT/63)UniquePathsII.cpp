// link->https://leetcode.com/problems/unique-paths-ii

class Solution
{
public:
    int f(int x, int y, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp)
    {
        if (x < 0 || y < 0 || obstacleGrid[x][y] == 1)
            return 0;
        if (x == 0 && y == 0)
            return 1;
        if (dp[x][y] != -1)
            return dp[x][y];
        int up = f(x - 1, y, obstacleGrid, dp);
        int left = f(x, y - 1, obstacleGrid, dp);
        return dp[x][y] = left + up;
    }

    int fITER(int x, int y, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp)
    {
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                if (obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else if (i == 0 and j == 0)
                    dp[i][j] = 1;
                else
                {
                    int up = 0;
                    if (i > 0)
                        up += dp[i - 1][j];
                    int left = 0;
                    if (j > 0)
                        left += dp[i][j - 1];
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[x - 1][y - 1];
    }

    int spaceOptimised(int x, int y, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp)
    {
        vector<int> prev(x);
        for (int i = 0; i < x; i++)
        {
            vector<int> curr(y);
            for (int j = 0; j < y; j++)
            {
                if (obstacleGrid[i][j] == 1)
                    curr[j] = 0;
                else if (i == 0 and j == 0)
                    curr[j] = 1;
                else
                {
                    int up = 0;
                    if (i > 0)
                        up += prev[j];
                    int left = 0;
                    if (j > 0)
                        left += curr[j - 1];
                    curr[j] = up + left;
                }
            }
            prev = curr;
        }
        return prev[y - 1];
    }

    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        // obstacle at 1
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return spaceOptimised(n, m, obstacleGrid, dp);
    }
};