// link->https://leetcode.com/problems/unique-paths/description/

class Solution {
public:
    int f(int x, int y, vector<vector<int>>&dp){
        if(x == 0 and y == 0) return 1;
        if(x<0 || y<0) return 0;
        if(dp[x][y] != -1)return dp[x][y];
        int sum = 0;
        int up = f(x-1, y,dp);
        int left = f(x,y-1,dp);
        return dp[x][y] = up + left;
    }

    int fITER(int x, int y, vector<vector<int>>& dp) {
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                if (i == 0 && j == 0) {
                    dp[0][0] = 1;
                } else {
                    int up = (i > 0) ? dp[i - 1][j] : 0;
                    int left = (j > 0) ? dp[i][j - 1] : 0;
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[x - 1][y - 1];
    }

    int SpaceOptimised(int x, int y, vector<vector<int>>& dp) {
        vector<int>prev(x,0);
        for (int i = 0; i < x; i++) {
            vector<int>curr(y,0);
            for (int j = 0; j < y; j++) {
                if (i == 0 && j == 0) {
                    curr[0] = 1;
                } else {
                    int up = (i > 0) ? prev[j] : 0;
                    int left = (j > 0) ? curr[j - 1] : 0;
                    curr[j] = up + left;
                }
            }
            prev = curr;
        }
        return prev[y - 1];
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n,-1));
        return SpaceOptimised(m,n,dp);
    }
};