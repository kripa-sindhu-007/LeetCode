class Solution {
private:
    bool helper(int i, int j, vector<vector<char>>& board, string& word,
                int idx) {

        if (idx == word.size())
            return true;

        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
            board[i][j] != word[idx])
            return false;

        char temp = board[i][j];
        board[i][j] = '&';

        bool decision = helper(i + 1, j, board, word, idx + 1) ||
                        helper(i, j + 1, board, word, idx + 1) ||
                        helper(i - 1, j, board, word, idx + 1) ||
                        helper(i, j - 1, board, word, idx + 1);

        board[i][j] = temp;
        return decision;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (helper(i, j, board, word, 0))
                    return true;
            }
        }

        return false;
    }
};