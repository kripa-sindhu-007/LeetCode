class Solution {
public:
    int uniquePaths(int m, int n) {
        int i = 0;
        int j = 0;
        int N = (m - i) + (n - j) - 2;
        int r = m - i - 1;
        double res = 1;
        for (int i = 1; i <= r; i++) {
            res = res * (N - r + i) / i;
        }
        return (int)res;
    }
};