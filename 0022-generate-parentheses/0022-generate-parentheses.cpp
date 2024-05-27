class Solution {
public:
    void helper(int n, vector<string>& ans, string temp, int start, int end) {
        if (temp.size() == (2 * n)) {
            ans.push_back(temp);
            return;
        }
        if (start < n)
            helper(n, ans, temp + '(', start + 1, end);
        if (end < start)
            helper(n, ans, temp + ')', start, end + 1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(n, ans, "", 0, 0);
        return ans;
    }
};