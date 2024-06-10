class Solution {
public:
    string longestPalindrome(string str) {
        int n = str.size();
        if (n == 0)
            return "";

        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int maxLength = 1;
        int start = 0;

        // All substrings of length 1 are palindromes
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }

        // Check for substrings of length 2
        for (int i = 0; i < n - 1; ++i) {
            if (str[i] == str[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLength = 2;
            }
        }

        // Check for lengths greater than 2
        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                if (str[i] == str[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    start = i;
                    maxLength = len;
                }
            }
        }

        return str.substr(start, maxLength);
    }
};
