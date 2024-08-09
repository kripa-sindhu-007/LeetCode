class Solution {
private:
    int helper(int n,vector<int>& dp){
        dp[0]=1;
        dp[1]=1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,0);
        return helper(n,dp);
        
    }
};