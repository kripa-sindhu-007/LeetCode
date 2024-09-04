class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0;
        int y = 0;
        int dir = 1; // 1:north , 2:east , 3:south , 4:west
        int dist = 0;

        set<pair<int, int>> obstacleSet;
        for (const auto& obstacle : obstacles) {
            obstacleSet.insert({obstacle[0], obstacle[1]});
        }

        for (int& command : commands) {
            if (command == -2) {
                if (dir == 1)
                    dir = 4;
                else
                    dir--;
            } else if (command == -1) {
                if (dir == 4)
                    dir = 1;
                else
                    dir++;
            } else if (1 <= command && command <= 9) {
                for (int i = 1; i <= command; i++) {
                    int temp_x = x;
                    int temp_y = y;
                    if (dir == 1)
                        temp_y++;
                    else if (dir == 2)
                        temp_x++;
                    else if (dir == 3)
                        temp_y--;
                    else
                        temp_x--;
                    // vector<int> item = {temp_x, temp_y}; don't use vector as
                    // searching in it will take linear time while using set it
                    // can be done in O(1).
                    if (obstacleSet.find({temp_x, temp_y}) != obstacleSet.end())
                        break;

                    x = temp_x;
                    y = temp_y;
                    int temp_dist = (x * x) + (y * y);
                    dist = max(dist, temp_dist);
                }
            }
        }
        return dist;
    }
};