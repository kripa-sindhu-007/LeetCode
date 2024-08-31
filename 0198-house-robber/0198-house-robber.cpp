class Solution {
public:
    int rob(vector<int>& nums) {
        int odd = 0, even = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i & 1)
                odd = max(nums[i] + odd, even);
            else
                even = max(even + nums[i], odd);
        }
        return max(odd, even);
    }
};