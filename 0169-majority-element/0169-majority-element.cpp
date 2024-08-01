class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj_ele;
        int count = 0;
        for (int i : nums) {
            if (count == 0) {
                count = 1;
                maj_ele = i;
            } else if (i == maj_ele)
                count++;
            else
                count--;
        }
        return maj_ele;
    }
};