class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_sum = 0;
        int max_sum = INT_MIN;
        int neg_max = INT_MIN;
        int count = 0;
        for (int it : nums) {
            curr_sum += it;
            if (curr_sum < 0)
                curr_sum = 0;
            // edge case if all numbers in array are negative
            if (it < 0) {
                count++;
                neg_max = max(neg_max, it);
            }
            max_sum = max(max_sum, curr_sum);
        }
        return (count == nums.size()) ? neg_max : max_sum;
    }
};