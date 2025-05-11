class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int max_dist = 0;
        int min_till_now = arrays[0][0];
        int max_till_now = arrays[0].back();

        for (int i = 1; i < arrays.size(); i++) {
            max_dist = max(max_dist, abs(arrays[i].back() - min_till_now));
            max_dist = max(max_dist, abs(max_till_now - arrays[i][0]));
            min_till_now = min(min_till_now, arrays[i][0]);
            max_till_now = max(max_till_now, arrays[i].back());
        }
        return max_dist;
    }
};