class Solution {
public:
    int maxSum(vector<int> nums) {
        int n = nums.size();
        int fs = 0, ss = 0;
        for (int i = 0; i < n; i++) {
            if (i & 1)
                fs = max(fs + nums[i], ss);
            else
                ss = max(ss + nums[i], fs);
        }
        return max(fs, ss);
    }
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 1)
            return nums[0];
        return max(maxSum(vector<int>(nums.begin(), nums.end() - 1)),
                   maxSum(vector<int>(nums.begin() + 1, nums.end())));
    }
};