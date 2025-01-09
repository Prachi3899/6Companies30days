class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q; // Queue to store the position of rotten oranges
        int freshCount = 0;      // Count of fresh oranges

        // Initialize the queue with all rotten oranges and count fresh oranges
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    ++freshCount;
                }
            }
        }

        // If there are no fresh oranges, return 0
        if (freshCount == 0) return 0;

        int minutes = 0;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // 4 possible directions

        // Perform BFS
        while (!q.empty()) {
            int size = q.size();
            bool rotten = false;

            for (int i = 0; i < size; ++i) {
                auto [x, y] = q.front();
                q.pop();

                for (auto [dx, dy] : directions) {
                    int nx = x + dx;
                    int ny = y + dy;

                    // Check if the adjacent cell is a fresh orange
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2; // Rot the orange
                        q.push({nx, ny});
                        --freshCount;
                        rotten = true;
                    }
                }
            }

            // Increment minutes only if any oranges were rotten in this step
            if (rotten) ++minutes;
        }

        // If there are still fresh oranges, return -1
        return freshCount == 0 ? minutes : -1;
    }
};
