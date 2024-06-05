class Solution {
public:
    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int empty_square = 1;
    int backtrack_function(vector<vector<int>>& grid, int startX, int startY) {
        if (grid[startX][startY] == 2)
            return (empty_square == 0) ? 1 : 0;
        grid[startX][startY] = -1;
        empty_square--;
        int unique_path = 0;
        for (auto direction : directions) {
            int newX = direction.first + startX;
            int newY = direction.second + startY;
            if (newX >= 0 && newY >= 0 && newX < grid.size() &&
                newY < grid[0].size() && grid[newX][newY] != -1)
                unique_path += backtrack_function(grid, newX, newY);
        }
        grid[startX][startY] = 0;
        empty_square++;
        return unique_path;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int startX = 0, startY = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    startX = i;
                    startY = j;
                } else if (grid[i][j] == 0)
                    empty_square++;
            }
        }
        return backtrack_function(grid, startX, startY);
    }
};