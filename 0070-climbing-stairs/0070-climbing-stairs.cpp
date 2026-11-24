class Solution {
public:
    int step(int stairs, int n, vector<int>&dp){
        if(stairs == n){
            return 1;
        }

        if(stairs > n){
            return 0;
        }

        if(dp[stairs] != -1){
            return dp[stairs];
        }

        dp[stairs] = step(stairs+1, n, dp) + step(stairs+2, n, dp);
        return dp[stairs];
    }

    int climbStairs(int n) {
        vector<int>dp(n+2, -1);
        dp[n] = 1;
        dp[n+1] = 0;
        return step(0, n, dp);
    }
};