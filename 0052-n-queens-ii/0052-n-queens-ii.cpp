class Solution {
private:
    void helper(int n, int row, int& distinct_sol, vector<bool>& isColAttacked,
                vector<bool>& isMainDiagAttacked,
                vector<bool>& isAntiDiagAttacked) {
        if (n == row) {
            distinct_sol += 1;
            return;
        }

        for (int col = 0; col < n; col++) {

            int mainDiag_idx = row - col + (n - 1);
            int antiDiag_idx = row + col;

            if (isColAttacked[col] || isMainDiagAttacked[mainDiag_idx] ||
                isAntiDiagAttacked[antiDiag_idx])
                continue;

            isColAttacked[col] = true;
            isMainDiagAttacked[mainDiag_idx] = true;
            isAntiDiagAttacked[antiDiag_idx] = true;

            helper(n, row + 1, distinct_sol, isColAttacked, isMainDiagAttacked,
                   isAntiDiagAttacked);

            isColAttacked[col] = false;
            isMainDiagAttacked[mainDiag_idx] = false;
            isAntiDiagAttacked[antiDiag_idx] = false;
        }
    }

public:
    int totalNQueens(int n) {
        int distinct_sol = 0;
        int row = 0;
        vector<bool> isColAttacked(n, false);
        vector<bool> isMainDiagAttacked(2 * n + 1, false);
        vector<bool> isAntiDiagAttacked(2 * n + 1, false);
        helper(n, row, distinct_sol, isColAttacked, isMainDiagAttacked,
               isAntiDiagAttacked);
        return distinct_sol;
    }
};