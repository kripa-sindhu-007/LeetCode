class Solution {
private:
    void backtrack(vector<int>& candidates, int target,
                   vector<vector<int>>& combi_sum, vector<int>& curr_sum,
                   int start, int sum) {

        if (sum > target)
            return;

        if (sum == target) {
            combi_sum.push_back(curr_sum);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            sum += candidates[i];
            curr_sum.push_back(candidates[i]);
            backtrack(candidates, target, combi_sum, curr_sum, i, sum);
            curr_sum.pop_back();
            sum -= candidates[i];
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> combi_sum;
        vector<int> curr_sum;
        int start = 0;
        int sum = 0;
        backtrack(candidates, target, combi_sum, curr_sum, start, sum);
        return combi_sum;
    }
};