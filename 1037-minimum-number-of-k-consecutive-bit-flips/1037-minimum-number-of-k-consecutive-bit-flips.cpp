class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int flips = 0;
        int currentFlips = 0;
        for (int i = 0; i < n; i++) {
            if (i >= k && nums[i - k] == 2) {
                currentFlips--;
            }
            if ((currentFlips % 2 + nums[i]) % 2 == 0) {
                if (i >= n - k + 1)
                    return -1;
                flips++;
                currentFlips++;
                nums[i] = 2;
            }
        }
        return flips;
    }
};