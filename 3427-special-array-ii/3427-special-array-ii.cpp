class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool>result;
        vector<int>count_pairs;
        count_pairs.push_back(0);
        int count=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]%2==nums[i-1]%2) count++;
            count_pairs.push_back(count);
        }

        for(auto it:queries){
            result.push_back(count_pairs[it[0]]==count_pairs[it[1]]);
        }
        return result;
        
    }
};