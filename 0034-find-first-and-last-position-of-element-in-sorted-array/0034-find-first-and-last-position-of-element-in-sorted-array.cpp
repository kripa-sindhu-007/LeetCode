class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int beg = 0;
        int end = nums.size() - 1;
        vector<int> pos = {-1, -1};

        // search for first pos
        while (beg <= end) {
            int mid = beg + (end - beg) / 2;
            if (nums[mid] == target) {
                pos[0] = mid;
                end = mid - 1;
            } else if (nums[mid] < target)
                beg = mid + 1;
            else
                end = mid - 1;
        }

        beg = 0;
        end = nums.size() - 1;
        // search for last pos
        while (beg <= end) {
            int mid = beg + (end - beg) / 2;
            if (nums[mid] == target) {
                pos[1] = mid;
                beg = mid + 1;
            } else if (nums[mid] < target)
                beg = mid + 1;
            else
                end = mid - 1;
        }
        return pos;
    }
};