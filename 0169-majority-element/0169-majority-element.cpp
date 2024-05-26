class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1] && count==(nums.size()/2)-1) return nums[i];
            else if(nums[i]==nums[i-1] && count!=(nums.size()/2)-1) count++;
            else count=0;
        }
        return nums[0];
    }
};