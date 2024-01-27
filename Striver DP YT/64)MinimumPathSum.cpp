// link->https://leetcode.com/problems/minimum-path-sum/

class Solution
{
public:
    int f(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (x == 0 && y == 0)
            return grid[0][0];
        if (x < 0 || y < 0)
            return 1e9;
        if (dp[x][y] != -1)
            return dp[x][y];
        int up = grid[x][y] + f(x - 1, y, grid, dp);
        int left = grid[x][y] + f(x, y - 1, grid, dp);
        return dp[x][y] = min(left, up);
    }

    int fITER(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                if (i == 0 && j == 0)
                {
                    dp[0][0] = grid[i][j];
                }
                else
                {
                    int up = grid[i][j] + ((i > 0) ? dp[i - 1][j] : 1e9);
                    int left = grid[i][j] + ((j > 0) ? dp[i][j - 1] : 1e9);
                    dp[i][j] = min(left, up);
                }
            }
        }
        return dp[x - 1][y - 1];
    }

    int spaceOptimised(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        vector<int> prev(x);
        for (int i = 0; i < x; i++)
        {
            vector<int> curr(y);
            for (int j = 0; j < y; j++)
            {
                if (i == 0 && j == 0)
                {
                    curr[0] = grid[i][j];
                }
                else
                {
                    int up = grid[i][j] + ((i > 0) ? prev[j] : 1e9);
                    int left = grid[i][j] + ((j > 0) ? curr[j - 1] : 1e9);
                    curr[j] = min(left, up);
                }
            }
            prev = curr;
        }
        return prev[y - 1];
    }

    int minPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return spaceOptimised(n, m, grid, dp);
    }
};