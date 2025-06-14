class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (size < 3)
            return size;
        int idx = 2;
        for (int i = 2; i < size; i++) {
            if (nums[i] != nums[idx - 2])
                nums[idx++] = nums[i];
        }
        return idx;
    }
};