class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged_intervals;
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < intervals.size(); i++) {
            if (merged_intervals.size() == 0 ||
                merged_intervals.back()[1] < intervals[i][0]) {
                merged_intervals.push_back(intervals[i]);
            } else {
                merged_intervals.back()[1] =
                    max(merged_intervals.back()[1], intervals[i][1]);
            }
        }
        return merged_intervals;
    }
};