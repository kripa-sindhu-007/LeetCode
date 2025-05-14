class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int beg = 0, end = nums.size() - 1;
        while (beg < end) {
            if (nums[beg] + nums[end] == target) {
                ans.push_back(beg + 1);
                ans.push_back(end + 1);
                break;
            } else if (nums[beg] + nums[end] > target)
                end--;
            else
                beg++;
        }
        return ans;
    }
};