// link->https://leetcode.com/problems/minimum-falling-path-sum/

class Solution
{
public:
    int f(int i, int j, int n, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    { // TLE
        if (j < 0 || j >= n)
            return 1e8;
        if (i == 0)
            return dp[i][j] = matrix[i][j];
        if (dp[i][j] != -1)
            return dp[i][j];
        int up = matrix[i][j] + f(i - 1, j, n, matrix, dp);
        int left = matrix[i][j] + f(i - 1, j - 1, n, matrix, dp);
        int right = matrix[i][j] + f(i - 1, j + 1, n, matrix, dp);
        return dp[i][j] = min({up, left, right});
    }

    int fITER(int x, int y, int n, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        for (int j = 0; j < n; j++)
        {
            dp[0][j] = matrix[0][j];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int up = matrix[i][j] + (j > 0 ? dp[i - 1][j - 1] : 1e8);
                int left = matrix[i][j] + dp[i - 1][j];
                int right = matrix[i][j] + (j < n - 1 ? dp[i - 1][j + 1] : 1e8);
                dp[i][j] = min({up, left, right});
            }
        }
        int mini = 1e8;
        for (int j = 0; j < n; j++)
        {
            mini = min(mini, dp[n - 1][j]);
        }
        return mini;
    }

    int spaceOptimised(int x, int y, int n, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        vector<int> prev(n, 0), curr(n, 0);
        for (int j = 0; j < n; j++)
        {
            prev[j] = matrix[0][j];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int up = matrix[i][j] + (j > 0 ? prev[j - 1] : 1e8);
                int left = matrix[i][j] + prev[j];
                int right = matrix[i][j] + (j < n - 1 ? prev[j + 1] : 1e8);
                curr[j] = min({up, left, right});
            }
            prev = curr;
        }
        int mini = 1e8;
        for (int j = 0; j < n; j++)
        {
            mini = min(mini, prev[j]);
        }
        return mini;
    }

    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        // FOR RECURSIVE SOL

        // int mini = INT_MAX;
        // for(int j = 0; j < n; j++) {
        //     mini = min(mini, f(n-1, j, n, matrix, dp));
        // }
        // return mini;

        return spaceOptimised(n - 1, 0, n, matrix, dp);
    }
};