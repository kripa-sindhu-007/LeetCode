class Solution {
private:
    void reverse(vector<int>& row) {
        int beg = 0;
        int end = row.size() - 1;
        while (beg < end)
            swap(row[beg++], row[end--]);
    }

public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < n; i++) {
            reverse(matrix[i]);
        }
    }
};