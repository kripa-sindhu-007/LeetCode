class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        vector<int> left_prd(n, 1);
        vector<int> right_prd(n, 1);

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                left_prd[i] = nums[i];
                continue;
            }
            left_prd[i] = left_prd[i - 1] * nums[i];
        }

        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1) {
                right_prd[i] = nums[i];
                continue;
            }
            right_prd[i] = right_prd[i + 1] * nums[i];
        }

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                ans[i] = right_prd[i + 1];
                continue;
            }
            if (i == n - 1) {
                ans[i] = left_prd[i - 1];
                continue;
            }
            ans[i] = left_prd[i - 1] * right_prd[i + 1];
        }
        return ans;
    }
};