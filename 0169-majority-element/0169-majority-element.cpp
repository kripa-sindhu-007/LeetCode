class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int curr_ele;
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                curr_ele = nums[i];
                count++;
            }
            else if (nums[i] == curr_ele) {
                count++;
            } else
                count--;
        }
        return curr_ele;
    }
};