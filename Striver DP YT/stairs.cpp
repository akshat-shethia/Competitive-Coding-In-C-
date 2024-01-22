// link->https://leetcode.com/problems/climbing-stairs/

class Solution
{
public:
    int fBOT(int n, int i, vector<int> &dp)
    {
        if (i >= n - 1)
            return 1;
        if (i == n)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        return dp[i] = fBOT(n, i + 1, dp) + fBOT(n, i + 2, dp);
    }
    int fTOP(int n, vector<int> &dp)
    {
        if (n == 1 || n == 2)
            return n;
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = fTOP(n - 1, dp) + fTOP(n - 2, dp);
    }

    int climbStairs(int n)
    {
        vector<int> dp;
        dp.resize(n + 1, -1);
        return fTOP(n, dp);
    }
};
