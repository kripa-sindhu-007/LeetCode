class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        vector<vector<int>> merged_intervals;
        int i = 0;
        int size = intervals.size();

        // taking all the left valid intervals of the new one
        while (i < size && intervals[i][1] < newInterval[0]) {
            merged_intervals.push_back(intervals[i]);
            i++;
        }

        // merged the overlapping if present
        while (i < size && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        merged_intervals.push_back(newInterval);

        //insert the right valid interval in result
        while (i < size) {
            merged_intervals.push_back(intervals[i]);
            i++;
        }
        return merged_intervals;
    }
};