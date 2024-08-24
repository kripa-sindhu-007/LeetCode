class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> map;
        for (int i = 0; i < order.size(); i++) {
            map[order[i]] = i;
        }

        sort(s.begin(), s.end(), [&](char a, char b) {
            if (map.count(a) && map.count(b)) {
                return map[a] < map[b];
            } else if (map.count(a))
                return true;
            else if (map.count(b))
                return false;
            else
                return a < b;
        });

        return s;
    }
};