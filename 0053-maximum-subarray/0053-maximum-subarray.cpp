class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_sum=0;
        int max_sum=INT_MIN;

        //covering edge case when all element in the array is negative
        int count=0;
        for(int it:nums){
            if(it>0) count++;
            max_sum=max(max_sum,it);
        }
        if(count==0) return max_sum;
        else max_sum=0;
        

        //works only when there is atleast 1 positive element in array
        for(int it : nums){
            curr_sum+=it;
            if(curr_sum>=0) max_sum=max(max_sum,curr_sum);
            else curr_sum=0;
        }

        return max_sum;
        
    }
};