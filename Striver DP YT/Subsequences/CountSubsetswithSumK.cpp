// link->https://www.codingninjas.com/studio/problems/count-subsets-with-sum-k_3952532

const int MOD = 1e9 + 7;

int f(int n, int k, vector<int> &arr, vector<vector<int>> &dp)
{
    if (k == 0)
        return 1;
    if (n == 0)
        return arr[n] == k;
    if (dp[n][k] != -1)
        return dp[n][k];
    int pick = 0;
    if (arr[n] <= k)
        pick = f(n - 1, k - arr[n], arr, dp);
    int Notpick = f(n - 1, k, arr, dp);
    return dp[n][k] = (pick + Notpick) % MOD;
}

int fITER(int n, int k, vector<int> &arr, vector<vector<int>> &dp)
{
    for (int i = 0; i < n; i++)
        dp[i][0] = 1;
    if (arr[0] <= k)
        dp[0][arr[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            int pick = 0;
            if (arr[i] <= j)
                pick = dp[i - 1][j - arr[i]];
            int Notpick = dp[i - 1][j];
            dp[i][j] = (pick + Notpick) % MOD;
        }
    }
    return dp[n - 1][k];
}

int spaceOptimised(int n, int k, vector<int> &arr, vector<vector<int>> &dp)
{
    vector<int> prev(k + 1, 0), curr(k + 1, 0);
    prev[0] = 1;
    if (arr[0] <= k)
        prev[arr[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            int pick = 0;
            if (arr[i] <= j)
                pick = prev[j - arr[i]];
            int notPick = prev[j];
            curr[j] = (pick + notPick) % MOD;
        }
        prev = curr;
    }
    return prev[k];
}

int findWays(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, 0)); // Initialize dp with 0
    return spaceOptimised(n, k, arr, dp);
}