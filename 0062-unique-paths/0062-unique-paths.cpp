class Solution {
public:
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m, vector<int>(n, 0));
        // dp[0][0] = 1;
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if (i > 0)
        //             dp[i][j] += dp[i - 1][j]; // from top
        //         if (j > 0)
        //             dp[i][j] += dp[i][j - 1]; // from left
        //     }
        // }
        // return dp[m - 1][n - 1];
        int i = 0; // start coordinate
        int j = 0; // start coordinate
        int N = (m - i - 1) + (n - j - 1);
        int r = m - i - 1;
        double res = 1;
        for (int i = 1; i <= r; i++) {
            res = res * (N - r + i) / i;
        }
        return (int)res;
    }
};