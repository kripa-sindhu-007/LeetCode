class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int max_count = 0;
        for (int it:nums) {
            if (it == 1)
                count++;
            else 
                count = 0;
            max_count = max(max_count, count);
        }
        return max_count;
    }
};