class Solution {
public:
    int rev(int num) {
        int rever = 0;
        while (num > 0) {
            rever = (rever * 10) + (num % 10);
            num /= 10;
        }
        return rever;
    }
    int countDistinctIntegers(vector<int>& nums) {
        int size = nums.size();
        for (int i = 0; i < size; i++)
            nums.push_back(rev(nums[i]));
        set<int> ans;
        for (int it : nums)
            ans.insert(it);
        return ans.size();
    }
};