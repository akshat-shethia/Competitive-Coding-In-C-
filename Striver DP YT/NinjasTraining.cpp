// link->https://www.codingninjas.com/studio/problems/ninja%E2%80%99s-training_3621003

int f(int n, int prev, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if (dp[n][prev] != -1)
        return dp[n][prev];
    if (n == 0)
    {
        int maxi = -1e8;
        for (int i = 0; i < 3; i++)
        {
            if (i != prev)
            {
                maxi = max(maxi, points[0][i]);
            }
        }
        return dp[n][prev] = maxi;
    }
    int maxi = -1e8;
    for (int i = 0; i < 3; i++)
    {
        if (i != prev)
        {
            int point = points[n][i] + f(n - 1, i, points, dp);
            maxi = max(maxi, point);
        }
    }
    return dp[n][prev] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n + 1, vector<int>(4, -1));
    return f(n - 1, 3, points, dp);
}
