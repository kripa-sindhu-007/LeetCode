class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> map;
        for (int it : arr)
            map[it]++;

        priority_queue<pair<int, int>> pq;

        for (auto it : map) {
            pq.push({it.second, it.first});
        }
        int count = 0;
        int size = arr.size();
        int removed_size = 0;

        while (removed_size < size / 2) {
            removed_size += pq.top().first;
            pq.pop();
            count++;
        }
        return count;
    }
};