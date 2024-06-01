class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ballColor;
        unordered_set<int> distinctColor;
        vector<int> result;

        for (auto query : queries) {
            int ball = query[0];
            int color = query[1];

            if (ballColor.find(ball) != ballColor.end()) {
                int oldColor = ballColor[ball];
                ballColor[ball] = color;
                bool inUse = false;
                for (auto pair : ballColor) {
                    if (pair.second == oldColor) {
                        inUse = true;
                        break;
                    }
                }
                if (!inUse) {
                    distinctColor.erase(oldColor);
                }
            } else {
                ballColor[ball] = color;
            }
            distinctColor.insert(color);
            result.push_back(distinctColor.size());
        }
        return result;
    }
};