class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int fs=0,ss=0;
        for(int i=0;i<n;i++){
            if(i&1) fs=max(fs+nums[i],ss);
            else ss=max(ss+nums[i],fs);
        }
        return max(fs,ss);
        
    }
};