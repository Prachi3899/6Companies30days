class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> result(m, vector<int>(n, 0)); // Result matrix initialized to 0
        
        // Directions for the 8 neighbors and the cell itself
        vector<int> directions = {-1, 0, 1};
        
        // Iterate over each cell in the matrix
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int sum = 0;
                int count = 0;
                
                // Check all neighbors in the 3x3 grid
                for (int di : directions) {
                    for (int dj : directions) {
                        int ni = i + di;
                        int nj = j + dj;
                        
                        // Check boundaries
                        if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                            sum += img[ni][nj];
                            ++count;
                        }
                    }
                }
                
                // Store the floored average in the result matrix
                result[i][j] = sum / count;
            }
        }
        
        return result;
    }
};
