class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_sum = 0;
        int max_sum = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            if (curr_sum < 0)
                curr_sum = 0;
            curr_sum += nums[i];
            max_sum = max(max_sum, curr_sum);
        }
        return max_sum;
    }
};