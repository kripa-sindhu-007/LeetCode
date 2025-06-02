class Solution {
private:
    void backtrack(vector<string>& all_combi, int n, int open, int close,
                   string curr_combi) {
        if (curr_combi.length() == 2 * n) {
            all_combi.push_back(curr_combi);
            return;
        }
        if (open < n) {
            backtrack(all_combi, n, open + 1, close, curr_combi + '(');
        }
        if (close < open) {
            backtrack(all_combi, n, open, close + 1, curr_combi + ')');
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> all_combi;
        int open = 0;
        int close = 0;
        string curr_combi = "";
        backtrack(all_combi, n, open, close, curr_combi);
        return all_combi;
    }
};