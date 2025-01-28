class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        
        // Initialize the height matrix with -1 for unvisited cells
        vector<vector<int>> height(m, vector<int>(n, -1));
        queue<pair<int, int>> q; // Queue for BFS

        // Directions for north, south, east, west
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // Add all water cells to the queue and set their height to 0
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isWater[i][j] == 1) {
                    q.push({i, j});
                    height[i][j] = 0;
                }
            }
        }

        // Perform BFS
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;

                // Check if the neighbor is within bounds and unvisited
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && height[nx][ny] == -1) {
                    height[nx][ny] = height[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        return height;
    }
};
