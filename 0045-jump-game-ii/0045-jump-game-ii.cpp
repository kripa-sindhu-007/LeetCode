class Solution {
public:
    int jump(vector<int>& nums) {
        int left = 0, right = 0;
        int jump = 0;
        while (right < nums.size() - 1) {
            int maxjump = 0;
            for (int i = left; i <= right; i++) {

                maxjump = max(maxjump, nums[i] + i);
            }
            left = right + 1;
            right = maxjump;
            jump++;
        }
        return jump;
    }
};