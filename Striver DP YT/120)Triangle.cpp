// link->https://leetcode.com/problems/triangle/description/

class Solution
{
public:
    int f(int i, int j, int n, vector<vector<int>> &triangle, vector<vector<int>> &dp)
    {
        if (i == n - 1)
            return dp[i][j] = triangle[i][j];
        if (dp[i][j] != -1)
            return dp[i][j];
        int down = triangle[i][j] + f(i + 1, j, n, triangle, dp);
        int diag = triangle[i][j] + f(i + 1, j + 1, n, triangle, dp);
        return dp[i][j] = min(down, diag);
    }

    int fITER(int i, int j, int n, vector<vector<int>> &triangle, vector<vector<int>> &dp)
    {
        for (int i = 0; i < n; i++)
        {
            dp[n - 1][i] = triangle[n - 1][i];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i; j >= 0; j--)
            {
                int up = triangle[i][j] + dp[i + 1][j];
                int diag = triangle[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(up, diag);
            }
        }
        return dp[0][0];
    }

    int spaceOptimised(int i, int j, int n, vector<vector<int>> &triangle, vector<vector<int>> &dp)
    {
        vector<int> next(n, 0), curr(n, 0);
        for (int i = 0; i < n; i++)
        {
            next[i] = triangle[n - 1][i];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i; j >= 0; j--)
            {
                int up = triangle[i][j] + next[j];
                int diag = triangle[i][j] + next[j + 1];
                curr[j] = min(up, diag);
            }
            next = curr;
        }
        return next[0];
    }

    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return spaceOptimised(0, 0, n, triangle, dp);
    }
};
