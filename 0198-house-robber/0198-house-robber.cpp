class Solution {
public:
    int rob(vector<int>& nums) {
        int odd_houses_amount = 0;
        int even_houses_amount = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0)
                even_houses_amount =
                    max(even_houses_amount + nums[i], odd_houses_amount);
            else
                odd_houses_amount =
                    max(odd_houses_amount + nums[i], even_houses_amount);
        }
        return max(even_houses_amount, odd_houses_amount);
    }
};