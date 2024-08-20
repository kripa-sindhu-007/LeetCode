class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<vector<int>>& result,
               vector<int>& combination, int start) {
        if (target == 0) {
            result.push_back(combination);
            //combination.clear();
            return;
        }
        for (int i = start; i < candidates.size() && target >= candidates[i];
             ++i) {

            combination.push_back(candidates[i]);

            solve(candidates, target - candidates[i], result, combination,
                      i);

            combination.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        sort(candidates.begin(),candidates.end());
        solve(candidates, target, result, combination, 0);
        return result;
    }
};