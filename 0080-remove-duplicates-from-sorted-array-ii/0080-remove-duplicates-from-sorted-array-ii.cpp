class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(count<2 || nums[count-2]!=nums[i]){
                nums[count]=nums[i];
                count++;
            }
        }
        return count;
    }
};