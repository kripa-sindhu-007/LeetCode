class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos,
                vector<int>& rowCosts, vector<int>& colCosts) {

        // int n = rowCosts.size();
        // int m = colCosts.size();
        // vector<vector<int>> dp(n, vector<int>(m, 0));
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         if (i == startPos[0] && j == startPos[1]) {
        //             dp[i][j] = 0;
        //         } else {
        //             int up = rowCosts[i];
        //             if (i > 0)
        //                 up += dp[i - 1][j]; // from up
        //             else
        //                 up += 1e8;

        //             int down = rowCosts[i];
        //             if (i < n - 1)
        //                 down += dp[i + 1][j]; // from down
        //             else
        //                 down += 1e8;

        //             int left = colCosts[j];
        //             if (j > 0)
        //                 left+= dp[i][j - 1]; // from left
        //             else
        //                 left += 1e8;

        //             int right = colCosts[j];
        //             if (j < m - 1)
        //                 right += dp[i][j + 1]; // from right
        //             else
        //                 right += 1e8;

        //             dp[i][j] = min(min(up, down), min(left, right));
        //         }
        //     }
        // }
        // return dp[n-1][m-1];
        
         int totalCost = 0;

        // Vertical movement cost
        if (startPos[0] < homePos[0]) {
            for (int i = startPos[0] + 1; i <= homePos[0]; i++) {
                totalCost += rowCosts[i];
            }
        } else {
            for (int i = startPos[0] - 1; i >= homePos[0]; i--) {
                totalCost += rowCosts[i];
            }
        }

        // Horizontal movement cost
        if (startPos[1] < homePos[1]) {
            for (int i = startPos[1] + 1; i <= homePos[1]; i++) {
                totalCost += colCosts[i];
            }
        } else {
            for (int i = startPos[1] - 1; i >= homePos[1]; i--) {
                totalCost += colCosts[i];
            }
        }

        return totalCost;
    }
};