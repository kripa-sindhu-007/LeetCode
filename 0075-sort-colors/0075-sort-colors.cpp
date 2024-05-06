class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count0=0,count1=0,count2=0;

        for(int it:nums){
            if(it==0) count0++;
            else if(it==1) count1++;
            else count2++;
        }

        int idx=0;
        while(count0--) nums[idx++]=0;
        while(count1--) nums[idx++]=1;
        while(count2--) nums[idx++]=2; 
        
    }
};