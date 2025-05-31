class Solution {
private:
    void backtrack(int n, int k, vector<vector<int>>& all_combination,
                   vector<int>& curr_combination, int first) {
        if (curr_combination.size() == k) {
            all_combination.push_back(curr_combination);
            return;
        }

        for (int i = first; i <= n; i++) {
            curr_combination.push_back(i);
            backtrack(n, k, all_combination, curr_combination, i + 1);
            curr_combination.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> all_combination;
        vector<int> curr_combination;
        int first = 1;
        backtrack(n, k, all_combination, curr_combination, first);
        return all_combination;
    }
};