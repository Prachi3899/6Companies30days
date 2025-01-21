class Solution {
public:
    // Check if the grid is connected
    bool isConnected(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int landCount = 0, components = 0;

        // Helper to perform DFS
        function<void(int, int)> dfs = [&](int i, int j) {
            if (i < 0 || j < 0 || i >= m || j >= n || visited[i][j] || grid[i][j] == 0)
                return;
            visited[i][j] = true;
            landCount++;
            dfs(i + 1, j);
            dfs(i - 1, j);
            dfs(i, j + 1);
            dfs(i, j - 1);
        };

        // Count components and land cells
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    components++;
                    if (components > 1) return false; // More than one component
                    dfs(i, j);
                }
            }
        }

        return landCount > 0 && components == 1;
    }

    int minDays(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // Step 1: Check if already disconnected
        if (!isConnected(grid)) return 0;

        // Step 2: Try removing one land cell
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    if (!isConnected(grid)) return 1; // Disconnected after one removal
                    grid[i][j] = 1; // Restore
                }
            }
        }

        // Step 3: Otherwise, return 2 (any grid can be disconnected in 2 days)
        return 2;
    }
};
