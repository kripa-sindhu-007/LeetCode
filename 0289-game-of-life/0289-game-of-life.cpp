class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                          {0, 1},   {1, -1}, {1, 0},  {1, 1}};

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int live_neighbors = 0;

                for (const auto& dir : directions) {
                    int ni = i + dir[0];
                    int nj = j + dir[1];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
                        (board[ni][nj] == 1 || board[ni][nj] == 2)) {
                        live_neighbors++;
                    }
                }

                if (board[i][j] == 1 &&
                    (live_neighbors < 2 || live_neighbors > 3)) {
                    board[i][j] =
                        2; // Mark it as a live cell that dies (state 2).
                }

                if (board[i][j] == 1 &&
                    (live_neighbors == 2 || live_neighbors == 3)) {
                    // No change needed; it remains 1.
                }

                if (board[i][j] == 0 && live_neighbors == 3) {
                    board[i][j] = 3; // Mark it as a dead cell that becomes
                                     // alive (state 3).
                }
            }
        }

        // Final pass to update the board to the new state
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 2) {
                    board[i][j] = 0; // Cell dies
                } else if (board[i][j] == 3) {
                    board[i][j] = 1; // Cell becomes alive
                }
            }
        }
    }
};