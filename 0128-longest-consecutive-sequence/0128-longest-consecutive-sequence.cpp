class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int max_len = 0;
        int curr_len = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                curr_len++;
                max_len = max(max_len, curr_len);
            } else if(nums[i]==nums[i-1]){
                max_len = max(max_len, curr_len);
            }
            else {
                curr_len = 1;
            }
            
        }
        return (nums.size() == 1) ? 1 : max_len;
    }
};