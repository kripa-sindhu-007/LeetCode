class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int, int> map;
        vector<int> uniquearr = arr;

        sort(uniquearr.begin(), uniquearr.end());
        uniquearr.erase(
            unique(uniquearr.begin(), uniquearr.end()),
            uniquearr.end());

        for (int it = 0; it < uniquearr.size(); it++) {
            map[uniquearr[it]] = it + 1;
        }

        vector<int> ans;

        for (auto it : arr) {
            ans.push_back(map[it]);
        }
        return ans;
    }
};