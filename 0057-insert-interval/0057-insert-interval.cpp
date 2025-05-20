class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> mergedIntervals;

        for (int i = 0; i < intervals.size(); i++) {
            if (i == 0 || mergedIntervals.back()[1] < intervals[i][0]) {
                mergedIntervals.push_back(intervals[i]);
            } else {
                mergedIntervals.back()[1] =
                    max(mergedIntervals.back()[1], intervals[i][1]);
            }
        }
        return mergedIntervals;
    }
};