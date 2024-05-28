class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if(nums.size()==1){
            if(nums[0]==1) return 1;
            else return 0;
        }
        
        int count=0;
        
        int max_count=0;
        for(int i=1;i<nums.size();i++){
            
            if(nums[i] == 1 && nums[i-1]==1){
                count++;
                max_count=max(max_count,count+1);
            }
            else count=0;
        }
        if(((nums[0]==1 && nums[1]!=1) || (nums[0]!=1 && nums[1]==1)) && max_count==0) max_count++;
        return max_count;
        
    }
};