class Solution {
public:
    int appendCharacters(string s, string t) {
        int count = 0;
        int i = 0, j = 0;
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                i++;
                j++;
                count++;
            } else {
                i++;
            }
        }
        return t.size() - count;
    }
};