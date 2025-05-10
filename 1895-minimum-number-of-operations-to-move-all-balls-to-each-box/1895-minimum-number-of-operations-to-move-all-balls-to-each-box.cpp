class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> has_balls;
        for (int pos = 0; pos < boxes.length(); pos++) {
            if (boxes[pos] == '1')
                has_balls.push_back(pos);
        }

        vector<int> min_moves;
        for (int i = 0; i < boxes.size(); i++) {
            int total_moves = 0;
            for (int j = 0; j < has_balls.size(); j++) {
                total_moves += abs(has_balls[j] - i);
            }
            min_moves.push_back(total_moves);
        }
        return min_moves;
    }
};