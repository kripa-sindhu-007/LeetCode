class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int it1 = m - 1;
        int it2 = n - 1;
        int mergedIt = m + n - 1;

        while (it1 >= 0 && it2 >= 0) {
            if (nums1[it1] > nums2[it2])
                nums1[mergedIt--] = nums1[it1--];
            else
                nums1[mergedIt--] = nums2[it2--];
        }

        while (it1 >= 0) {
            nums1[mergedIt--] = nums1[it1--];
        }
        while (it2 >= 0) {
            nums1[mergedIt--] = nums2[it2--];
        }
    }
};