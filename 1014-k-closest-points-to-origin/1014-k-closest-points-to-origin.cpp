class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, pair<int, int>>,
                       vector<pair<double, pair<int, int>>>>
            pq;

        for (auto it : points) {
            double dist = sqrt(it[0] * it[0] + it[1] * it[1]);
            pq.push({dist, {it[0], it[1]}});
            if (pq.size() > k)
                pq.pop();
        }
        vector<vector<int>> ans;

        while (!pq.empty()) {
            auto [dist, idx] = pq.top();
            int i = idx.first;
            int j = idx.second;
            ans.push_back({i, j});
            pq.pop();
        }
        return ans;
    }
};