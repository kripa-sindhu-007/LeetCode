class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size=nums.size();

        vector<int>LIS(size+1,1);

        for(int i=0;i<size;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j])
                LIS[i]=max(LIS[i],1+LIS[j]);
            }
        }

        int ans=0;
        for(auto it:LIS) ans=max(ans,it);

        return ans;
        
    }
};