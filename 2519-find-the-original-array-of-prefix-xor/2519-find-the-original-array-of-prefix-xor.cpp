class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> ans;
        int temp = 0;
        for (int i = 0; i < pref.size(); i++) {
            if (i > 0)
                temp = pref[i - 1];
            temp ^= pref[i];
            ans.push_back(temp);
        }
        return ans;
    }
};