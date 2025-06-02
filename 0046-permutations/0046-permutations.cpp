class Solution {
private:
    void backtrack(vector<vector<int>>& all_combi, vector<int> curr_combi,
                   vector<bool>& visited, vector<int>& nums) {
        if (curr_combi.size() >= nums.size()) {
            all_combi.push_back(curr_combi);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!visited[i]) {
                curr_combi.push_back(nums[i]);
                visited[i] = true;
                backtrack(all_combi, curr_combi, visited, nums);
                curr_combi.pop_back();
                visited[i] = false;
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> all_combi;
        vector<int> curr_combi;
        vector<bool> visited(nums.size(), false);
        backtrack(all_combi, curr_combi, visited, nums);
        return all_combi;
    }
};