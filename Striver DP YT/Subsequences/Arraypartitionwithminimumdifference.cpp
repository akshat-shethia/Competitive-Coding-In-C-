// link->https://www.codingninjas.com/studio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum._842494

bool f(int n, int sum, vector<int> &arr, vector<vector<bool>> &dp)
{
    if (sum == 0)
        return true;
    if (n < 0 || sum < 0)
        return false;
    if (dp[n][sum] != -1)
        return dp[n][sum];

    bool pick = false;
    if (arr[n] <= sum)
        pick = f(n - 1, sum - arr[n], arr, dp);
    bool notPick = f(n - 1, sum, arr, dp);

    dp[n][sum] = pick || notPick;

    return dp[n][sum];
}

bool fITER(int n, int sum, vector<int> &arr, vector<vector<bool>> &dp)
{
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            bool pick = false;
            if (arr[i - 1] <= j)
                pick = dp[i - 1][j - arr[i - 1]];
            bool notPick = dp[i - 1][j];
            dp[i][j] = pick || notPick;
        }
    }

    return dp[n][sum];
}

bool spaceOptimised(int n, int sum, vector<int> &arr, vector<vector<bool>> &dp)
{
    vector<int> prev(sum + 1, 0), curr(sum + 1, 0);
    prev[0] = curr[0] = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            bool pick = false;
            if (arr[i - 1] <= j)
                pick = prev[j - arr[i - 1]];
            bool notPick = prev[j];
            curr[j] = pick || notPick;
        }
        prev = curr;
    }

    return prev[sum];
}

int minSubsetSumDifference(vector<int> &arr, int n)
{
    int sum = 0;
    for (int ele : arr)
        sum += ele;

    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
    int x = 0;
    for (int i = sum / 2; i >= 0; i--)
    {
        if (spaceOptimised(n, i, arr, dp))
        {
            x = sum - 2 * i;
            break;
        }
    }
    return x;
}