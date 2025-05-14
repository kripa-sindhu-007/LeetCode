class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = INT_MIN;
        int beg = 0;
        int end = height.size() - 1;

        while (beg < end) {
            max_area =
                max(max_area, min(height[beg], height[end]) * (end - beg));
            (height[beg] < height[end]) ? beg++ : end--;
        }
        return max_area;
    }
};