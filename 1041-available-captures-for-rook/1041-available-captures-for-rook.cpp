class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        pair<int, int> rook_pos = {0, 0};
        int attacked_pawn = 0;
        vector<pair<int, int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        bool flag = false;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'R') {
                    rook_pos = {i, j};
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;
        }

        for (int i = 0; i < 4; i++) {
            int new_x=rook_pos.first;
            int new_y=rook_pos.second;

            while(true){
                new_x=new_x+direction[i].first;
                new_y=new_y+direction[i].second;
                if(new_x < 0 || new_x >= board.size() || new_y < 0 || new_y >= board[0].size()) break;
                else if(board[new_x][new_y] == 'B') break;
                else if(board[new_x][new_y] == 'p'){
                    attacked_pawn++;
                    break;
                }
            }
        }
        return attacked_pawn;
    }
};