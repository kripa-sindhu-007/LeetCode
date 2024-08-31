class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, maxlen = 1;

        for (int i = 0; i < s.size(); i++) {
            int left = i, right = i;
            while (right + 1 < s.size() && s[right] == s[right + 1])
                right++; // skip duplicate midpoint

            while (left > 0 && right + 1 < s.size() &&
                   s[left - 1] == s[right + 1]) {
                left--;
                right++;
            }
            int length = right - left + 1;
            if (length > maxlen) {
                start = left;
                maxlen = length;
            }
        }
        return s.substr(start, maxlen);
    }
};