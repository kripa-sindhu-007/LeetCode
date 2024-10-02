class Solution {
public:
    int climbStairs(int n) {
        // vector<int> dp(n + 1, -1);
        // return helper(n, dp);
        int prev1 = 1, prev2 = 1;

        for (int i = 2; i <= n; i++) {
            int temp = prev1 + prev2;
            prev2 = prev1;
            prev1 = temp;
        }
        return prev1;
    }

    // int helper(int n, vector<int>& dp) {
    //     dp[0] = 1;
    //     dp[1] = 1;

    //     for (int i = 2; i <= n; i++) {
    //         dp[i] = dp[i - 1] + dp[i - 2];
    //     }
    //     return dp[n];
    // }
};