class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int area = 0;
        while (left < right) {
            int h = min(height[left], height[right]);
            int w = right - left;
            area = max(area, h * w);
            height[left] < height[right] ? left++ : right--;
        }
        return area;
    }
};