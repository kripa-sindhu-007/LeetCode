class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, count = 0;
        unordered_map<int, int> mp; 
        mp[0] = 1; 

        for (int num : nums) {
            sum += num;
            if (mp.count(sum - k)) {
                count += mp[sum - k];
            }
            mp[sum]++;
        }

        return count;
    }
};
