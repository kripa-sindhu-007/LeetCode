class Solution {
public:
    bool canJump(vector<int>& nums) {
        int pos = 0;
        // int goal = nums.size() - 1;

        for (int i = 0; i < nums.size(); i++) {
            if (pos < i)
                return false;
            pos = max(pos, nums[i] + i);
        }
        return true;
    }
};