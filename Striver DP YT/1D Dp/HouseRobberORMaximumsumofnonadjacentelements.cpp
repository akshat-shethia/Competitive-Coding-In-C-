#include <bits/stdc++.h>
int f(int n, vector<int> &nums, vector<int> &dp)
{
    if (n == 0)
        return nums[0];
    if (n < 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int Selected = nums[n] + f(n - 2, nums, dp);
    int NotSelected = 0 + f(n - 1, nums, dp);
    return dp[n] = max(NotSelected, Selected);
}

int fITER(int n, vector<int> &nums, vector<int> &dp)
{
    dp[0] = nums[0];
    if (n < 0)
        return 0;
    for (int i = 1; i <= n; i++)
    {
        int selected = nums[i];
        if (i >= 2)
            selected = nums[i] + dp[i - 2];
        int NotSelected = 0 + dp[i - 1];
        dp[i] = max(NotSelected, selected);
    }
    return dp[n];
}

int fSpaceOptimised(int n, vector<int> &nums, vector<int> &dp)
{
    // Prev2, prev, curr
    int prev2 = 0;
    int prev = nums[0];
    if (n < 0)
        return 0;
    for (int i = 1; i <= n; i++)
    {
        int selected = nums[i];
        if (i >= 2)
            selected = nums[i] + prev2;
        int NotSelected = 0 + prev;
        int curr = max(NotSelected, selected);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    vector<int> dp;
    dp.clear();
    int n = nums.size();
    dp.resize(n + 1, 0);
    return fSpaceOptimised(n - 1, nums, dp);
}