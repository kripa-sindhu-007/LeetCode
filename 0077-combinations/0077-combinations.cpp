class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr_combi;
        helper(n, k, ans, curr_combi, 1);
        return ans;
    }
private:
    void helper (int n, int k, vector<vector<int>>& ans, vector<int>& curr_combi,
         int first) {

        if (curr_combi.size() == k) {
            ans.push_back(curr_combi);
            return;
        }
        for (int i = first; i <= n; i++) {
            curr_combi.push_back(i);              // choose
            helper(n, k, ans, curr_combi, i + 1); // explore
            curr_combi.pop_back();                // backtrack
        }
    }
};