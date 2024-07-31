class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int even = 0;
        int odd = 1;
        vector<int>ans(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                ans[even]=nums[i];
                even = even + 2;
            } else {
                ans[odd]=nums[i];
                odd = odd + 2;
            }
        }
        return ans;
    }
};