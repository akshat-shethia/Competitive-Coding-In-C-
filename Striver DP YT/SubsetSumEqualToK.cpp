// link->https://www.codingninjas.com/studio/problems/subset-sum-equal-to-k_1550954

#include <bits/stdc++.h>
bool f(int i, int sum, vector<int> &arr, vector<vector<bool>> &dp)
{
    if (dp[i][sum] != 0)
        return dp[i][sum];
    if (sum == 0)
        return true;
    if (i == 0)
    {
        return (arr[0] == sum);
    }
    int pick = false;
    if (arr[i] <= sum)
        pick = f(i - 1, sum - arr[i], arr, dp);
    int Notpick = f(i - 1, sum, arr, dp);
    return dp[i][sum] = (pick or Notpick);
}

bool fITER(int i, int sum, vector<int> &arr, vector<vector<bool>> &dp)
{
    // i have to make a tabulation of dp[i][sum]
    // sum can be 0 for all i
    for (int i = 0; i < arr.size(); i++)
    {
        dp[i][0] = true;
    }
    // when can i be 0; at all sum but only true when sum = arr[0];
    dp[0][arr[0]] = true;
    for (int i = 1; i < arr.size(); i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            int pick = false;
            if (arr[i] <= j)
                pick = dp[i - 1][j - arr[i]];
            int Notpick = dp[i - 1][j];
            dp[i][j] = pick or Notpick;
        }
    }
    return dp[i][sum];
}

bool spaceOptimised(int i, int sum, vector<int> &arr, vector<vector<bool>> &dp)
{
    vector<bool> prev(arr.size(), false), curr(sum + 1, false);
    prev[0] = curr[0] = true;
    // when can i be 0; at all sum but only true when sum = arr[0];
    prev[arr[0]] = true;
    for (int i = 1; i < arr.size(); i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            int pick = false;
            if (arr[i] <= j)
                pick = prev[j - arr[i]];
            int Notpick = prev[j];
            curr[j] = pick or Notpick;
        }
        prev = curr;
    }
    return prev[sum];
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));
    return spaceOptimised(n - 1, k, arr, dp);
}