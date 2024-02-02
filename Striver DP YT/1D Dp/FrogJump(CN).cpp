// link->https://www.codingninjas.com/studio/problems/frog-jump_3621012

#include <bits/stdc++.h>
vector<int> dp;
int f(int n, vector<int> &heights)
{
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int left = f(n - 1, heights) + abs(heights[n] - heights[n - 1]);
    int right = INT_MAX;
    if (n > 1)
        right = f(n - 2, heights) + abs(heights[n] - heights[n - 2]);
    return dp[n] = min(left, right);
}

int fITER(int n, vector<int> &heights)
{
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int left = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int right = INT_MAX;
        if (i > 1)
            right = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        dp[i] = min(left, right);
    }
    return dp[n - 1];
}


// SINCE WE ONLY NEED THHE PREV 2 VALS FOR THE CURR VAL PREV2, PREV, CURR WE CAN OPTIMSE THE SC
// DP[I-2] = PREV2; DP[I-1] = PREV; DP[I] = CURR;
int fSpaceOptimised(int n, vector<int> &heights)
{
    int prev = 0;
    int prev2 = 0;
    for (int i = 1; i < n; i++)
    {
        int left = prev + abs(heights[i] - heights[i - 1]);
        int right = INT_MAX;
        if (i > 1)
            right = prev2 + abs(heights[i] - heights[i - 2]);
        int curr = min(left, right);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}
int frogJump(int n, vector<int> &heights)
{
    dp.clear();
    dp.resize(n + 1, 0);
    return fSpaceOptimised(n, heights);
}
