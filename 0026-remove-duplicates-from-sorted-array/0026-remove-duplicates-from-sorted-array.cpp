class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 1;
        int count = 1; // 1st ele in the array is always valid.
        int curr_ele = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (curr_ele == nums[i])
                continue;
            else {
                count++;
                curr_ele = nums[i];
                swap(nums[i], nums[idx]);
                idx++;
            }
        }
        return count;
    }
};