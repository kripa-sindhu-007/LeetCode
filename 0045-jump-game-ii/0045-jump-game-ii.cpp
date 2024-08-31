class Solution {
private:
    int helper(vector<int>& nums, int curr, vector<int>& dp) {
        if (curr >= nums.size() - 1)
            return 0;
        if (dp[curr] != -1)
            return dp[curr];
        int minJump = 1e9;
        for (int i = nums[curr]; i >= 1; i--) {
            int jump = 1 + helper(nums, curr + i, dp);
            minJump = min(minJump, jump);
        }
        return dp[curr] = minJump;
    }

public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, -1);
        return helper(nums, 0, dp);
    }
};