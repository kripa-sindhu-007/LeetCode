class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> deg(n, 0);

        for (auto it = adj.begin(); it != adj.end(); it++) {
            for (auto nbr : adj[it->first]) {
                deg[nbr]++;
            }
        }

        vector<int> result;

        for (int i = 0; i < deg.size(); i++) {
            result.push_back((deg[i]));
        }

        sort(result.begin(), result.end(), greater<int>());

        long long int counter = n;
        long long int sum = 0;

        for (int i = 0; i < result.size(); i++) {
            sum = sum + 0LL + (counter * result[i] * 1LL);
            counter--;
        }

        return sum;
    }
};