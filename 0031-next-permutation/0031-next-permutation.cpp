class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx = -1;
        int n = nums.size();
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                idx = i;
                break;
            }
        }
        for (int i = n - 1; i > idx && idx != -1; i--) {
            if (nums[i] > nums[idx]) {
                swap(nums[idx], nums[i]);
                break;
            }
        }
        if (idx == -1)
            reverse(nums.begin(), nums.end());
        else
            reverse(nums.begin() + idx + 1, nums.end());
    }
};