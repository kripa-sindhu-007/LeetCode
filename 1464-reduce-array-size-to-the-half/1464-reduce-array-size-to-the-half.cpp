class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> map;
        for (int it : arr)
            map[it]++;

        vector<int>freq;

        for (auto it : map) {
            freq.push_back(it.second);
        }
        int count = 0;
        int size = arr.size();
        int removed_size = 0;

        sort(freq.begin(),freq.end(),greater<int>());

        while (removed_size < size / 2) {
            removed_size += *freq.begin();
            freq.erase(freq.begin());
            count++;
        }
        return count;
    }
};