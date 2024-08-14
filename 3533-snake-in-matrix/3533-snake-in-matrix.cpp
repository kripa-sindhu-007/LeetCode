class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int i = 0, j = 0;
        int pos = 0;
        for (string st : commands) {
            if (st == "UP") {
                i = i - 1;
                pos = (i * n) + j;
            } else if (st == "RIGHT") {
                j = j + 1;
                pos = (i * n) + j;
            }
            if (st == "DOWN") {
                i = i + 1;
                pos = (i * n) + j;
            }
            if (st == "LEFT") {
                j = j - 1;
                pos = (i * n) + j;
            }
        }
        return pos;
    }
};