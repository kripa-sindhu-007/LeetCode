class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> result;

        for (int i = 0; i < nums1.size(); i++) {
            int beg = 0;
            int end = nums2.size() - 1;
            while (beg <= end) {
                int mid = beg + (end - beg) / 2;
                if (nums2[mid]
                    == nums1[i]) {
                        if (find(result.begin(), result.end(),nums2[mid]) ==
                            result.end())
                            result.push_back(nums2[mid]);
                        break;
                    }
                else if (nums2[mid] > nums1[i])
                    end = mid - 1;
                else
                    beg = mid + 1;
            }
        }
        return result;
    }
};