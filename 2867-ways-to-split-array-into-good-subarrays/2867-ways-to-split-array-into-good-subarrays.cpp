class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        vector<int> v;
        bool first = false;
        int cnt = 0;
        // Iterate over the array
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                if (first)
                    v.push_back(cnt); // Store the count of consecutive zeros
                first = true;
                cnt = 0;
            } else {
                cnt++; // Count consecutive zeros
            }
        }
        if (!first)
            return 0; // If there is no '1' in the array, return 0
        long long ans = 1;
        long long mod = 1e9 + 7;
        // Multiply all counts by (count + 1) and take the modulo
        for (auto val : v) {
            ans = (ans * (val + 1)) % mod;
        }
        return ans;
    }
};