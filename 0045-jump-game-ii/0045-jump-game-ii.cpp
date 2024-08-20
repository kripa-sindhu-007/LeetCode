class Solution {
private:
    int solve(int curr, vector<int>& nums, vector<int>& dp) {
        if (curr >= nums.size() - 1)
            return 0;
        if (dp[curr] != -1)
            return dp[curr];
        int minJumps = 1e9;

        for (int i = nums[curr]; i >= 1; i--) {
            int jump = 1 + solve(curr + i, nums, dp);
            minJumps = min(minJumps, jump);
        }
        return dp[curr] = minJumps;
    }

public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, -1);
        int curr = 0;
        return solve(0, nums, dp);
    }
};