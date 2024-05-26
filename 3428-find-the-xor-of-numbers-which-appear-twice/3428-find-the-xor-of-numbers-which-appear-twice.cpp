class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int,int>map;
        for(int it:nums) map[it]++;
        int result=0;
        for(auto it:map){
            if(it.second>1) result=result^it.first;
        }
        return result;
        
    }
};