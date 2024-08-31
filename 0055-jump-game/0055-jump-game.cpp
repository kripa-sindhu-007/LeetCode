class Solution {
public:
    bool canJump(vector<int>& nums) {

        int maxPos=0;

        for(int i=0;i<nums.size();i++){
            if(maxPos<i) return false;
            maxPos=max(maxPos,i+nums[i]);

        }
        return true;
        
    }
};