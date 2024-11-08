class Solution {
    unordered_map<string, bool> memo;

    bool solve(string s1, string s2) {
        // Base cases
        if (s1 == s2)
            return true;
        if (s1.length() <= 1)
            return false;

        // Create key for memoization
        string key = s1 + "#" + s2;
        if (memo.find(key) != memo.end())
            return memo[key];

        int n = s1.length();
        bool result = false;

        // Check character frequency before recursion
        vector<int> count(26, 0);
        for (int i = 0; i < n; i++) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        // If character frequencies don't match, strings can't be scrambled
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0)
                return memo[key] = false;
        }

        // Try all possible splits
        for (int i = 1; i < n; i++) {
            // Case 1: No swap at this split
            bool noSwap = solve(s1.substr(0, i), s2.substr(0, i)) &&
                          solve(s1.substr(i), s2.substr(i));

            // Case 2: Swap at this split
            bool withSwap = solve(s1.substr(0, i), s2.substr(n - i)) &&
                            solve(s1.substr(i), s2.substr(0, n - i));

            if (noSwap || withSwap) {
                result = true;
                break;
            }
        }

        return memo[key] = result;
    }

public:
    bool isScramble(string s1, string s2) {
        // Clear memoization map for new test case
        memo.clear();

        // Check basic conditions
        if (s1.length() != s2.length())
            return false;
        if (s1 == s2)
            return true;

        return solve(s1, s2);
    }
};