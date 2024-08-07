class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        int max_len = INT_MIN;
        int curr_len;
        unordered_set<int> st;

        for (int i : nums)
            st.insert(i);

        for (int i : st) {
            if (st.find(i - 1) == st.end()) {
                curr_len = 1;
                int curr = i;
                while (st.find(curr + 1) != st.end()) {
                    curr = curr + 1;
                    curr_len += 1;
                }
                max_len = max(max_len, curr_len);
            }
        }
        return max_len;
    }
};