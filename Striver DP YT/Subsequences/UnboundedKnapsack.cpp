// link->https://www.codingninjas.com/studio/problems/unbounded-knapsack_1215029

vector<vector<int>> dp;

int f(int n, int w, vector<int> &profit, vector<int> &weight)
{
    if (n == 0)
    {
        return ((int)(w / weight[n]) * profit[n]);
    }
    if (dp[n][w] != -1)
        return dp[n][w];
    int take = -1e9;
    if (weight[n] <= w)
        take = profit[n] + f(n, w - weight[n], profit, weight);
    int notTake = f(n - 1, w, profit, weight);
    return dp[n][w] = max(take, notTake);
}

int fITER(int n, int w, vector<int> &profit, vector<int> &weight)
{
    for (int i = 0; i <= w; i++)
    {
        dp[0][i] = (i / weight[0]) * profit[0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            int take = 0;
            if (weight[i] <= j)
            {
                take = profit[i] + dp[i][j - weight[i]];
            }
            int notTake = dp[i - 1][j];
            dp[i][j] = max(take, notTake);
        }
    }
    return dp[n - 1][w];
}

int spaceOptimised(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<int> prev(w + 1, 0), curr(w + 1, 0);
    for (int i = 0; i <= w; i++)
    {
        prev[i] = (i / weight[0]) * profit[0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            int take = 0;
            if (weight[i] <= j)
            {
                take = profit[i] + curr[j - weight[i]];
            }
            int notTake = prev[j];
            curr[j] = max(take, notTake);
        }
        prev = curr;
    }
    return prev[w];
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    dp.assign(n, vector<int>(w + 1, -1));
    return spaceOptimised(n, w, profit, weight);
}