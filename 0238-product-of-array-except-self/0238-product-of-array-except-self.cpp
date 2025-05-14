class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                ans[i] = nums[i];
                continue;
            }
            ans[i] = ans[i - 1] * nums[i];
        }

        int right_prd = nums[n - 1];

        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1) {
                ans[i] = ans[i - 1];
                continue;
            }
            if (i == 0) {
                ans[i] = right_prd;
                continue;
            }
            ans[i] = ans[i - 1] * right_prd;
            right_prd *= nums[i];
        }

        return ans;
    }
};