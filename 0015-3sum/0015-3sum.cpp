class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int beg = i + 1;
            int end = nums.size() - 1;
            while (beg < end) {
                if (nums[i] + nums[beg] + nums[end] == 0) {
                    ans.push_back({nums[i], nums[beg], nums[end]});
                    beg++;
                    end--;
                    while (beg < end && nums[beg] == nums[beg - 1])
                        beg++;
                    while (end > beg && nums[end] == nums[end + 1])
                        end--;
                } else if (nums[i] + nums[beg] + nums[end] > 0)
                    end--;
                else
                    beg++;
            }
        }
        return ans;
    }
};