class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int n = score.size();
        int m = score[0].size();

        sort(score.begin(), score.end(),
             [k](vector<int> first, vector<int> second) {
                 return first[k] > second[k];
             });
        return score;
    }
};