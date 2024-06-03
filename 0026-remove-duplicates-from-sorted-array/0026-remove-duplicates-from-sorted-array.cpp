class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1;
        int idx = 1;
        int curr = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (curr == nums[i]) {
                continue;
            } else {
                count++;
                curr = nums[i];
                swap(nums[i], nums[idx]);
                idx++;
            }
        }
        return count;
    }
};