class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int size = citations.size();
        int maxH = 0;
        for (int i = 0; i < citations.size(); i++) {
            int h_candidate = size - i;
            if (citations[i] >= h_candidate) {
                maxH = h_candidate;
                break;
            }
        }
        return maxH;
    }
};