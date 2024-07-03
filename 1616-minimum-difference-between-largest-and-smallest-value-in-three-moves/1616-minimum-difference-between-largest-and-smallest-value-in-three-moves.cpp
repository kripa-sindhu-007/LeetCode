class Solution {
public:
    int backtrack(int left, int right, int index, vector<int>& nums) {
        if (index == 3)
            return nums[right] - nums[left];

        return min(backtrack(left, right - 1, index + 1, nums),
                   backtrack(left + 1, right, index + 1, nums));
    }
    int minDifference(vector<int>& nums) {
        if (nums.size() <= 4)
            return 0;

        sort(nums.begin(), nums.end());

        return backtrack(0, nums.size() - 1, 0, nums);
    }
};
