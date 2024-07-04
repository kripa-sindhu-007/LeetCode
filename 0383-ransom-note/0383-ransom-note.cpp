class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map;
        for (char c : magazine)
            map[c]++;
        for (char c : ransomNote)
            map[c]--;
        for (auto it : map)
            if (it.second < 0)
                return false;
        return true;
    }
};