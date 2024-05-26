class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries,
                                     int x) {
        vector<int> ans;
        vector<int> pos;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == x)
                pos.push_back(i);
        }
        for (int it : queries) {
            if (it > pos.size())
                ans.push_back(-1);
            else
                ans.push_back(pos[it - 1]);
        }
        return ans;
    }
};