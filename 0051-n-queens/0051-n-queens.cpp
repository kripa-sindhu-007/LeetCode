class Solution {
private:
    void helper(int n, int row, vector<vector<string>>& boards,
                vector<string>& board, vector<bool>& isColAttacked,
                vector<bool>& isMainDiagAttacked,
                vector<bool>& isAntiDiagAttacked) {
        if (n == row) {
            boards.push_back(board);
            return;
        }
        string rowArranged(n, '.');
        for (int col = 0; col < n; col++) {

            int mainDiag_idx = row - col + (n - 1);
            int antiDiag_idx = row + col;

            if (isColAttacked[col] || isMainDiagAttacked[mainDiag_idx] ||
                isAntiDiagAttacked[antiDiag_idx])
                continue;

            rowArranged[col] = 'Q';
            isColAttacked[col] = true;
            isMainDiagAttacked[mainDiag_idx] = true;
            isAntiDiagAttacked[antiDiag_idx] = true;
            board.push_back(rowArranged);

            helper(n, row + 1, boards, board, isColAttacked, isMainDiagAttacked,
                   isAntiDiagAttacked);

            rowArranged[col] = '.';
            isColAttacked[col] = false;
            isMainDiagAttacked[mainDiag_idx] = false;
            isAntiDiagAttacked[antiDiag_idx] = false;
            board.pop_back();
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> boards;
        vector<string> board;
        vector<bool> isColAttacked(n, false);
        vector<bool> isMainDiagAttacked(2 * n + 1, false);
        vector<bool> isAntiDiagAttacked(2 * n + 1, false);
        int row = 0;
        helper(n, row, boards, board, isColAttacked, isMainDiagAttacked,
               isAntiDiagAttacked);
        return boards;
    }
};