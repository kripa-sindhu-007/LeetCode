class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sorted = heights;
        int diff = 0;
        sort(sorted.begin(), sorted.end());
        for (int i = 0; i < heights.size(); i++)
            if (heights[i] != sorted[i])
                diff++;
        return diff;
    }
};