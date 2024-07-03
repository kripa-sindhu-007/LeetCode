class Solution {
public:
    bool validSubstring(string st) {
        unordered_map<char, int> map;
        for (auto it : st)
            map[it]++;
        for (auto it : map)
            if (it.second > 2)
                return false;
        return true;
    }
    int maximumLengthSubstring(string s) {
        int max_length = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = s.size() - 1; j >= 0; j--) {
                if (validSubstring(s.substr(i, j - i + 1))) {
                    max_length = max(max_length, j - i + 1);
                    break;
                }
            }
        }
        return max_length;
    }
};