class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Hash sets to track digits in rows, columns, and sub-boxes
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);

        // Iterate through each cell of the board
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char num = board[i][j];
                if (num == '.') continue;

                // Calculate box index
                int boxIndex = (i / 3) * 3 + (j / 3);

                // Check if the number exists in the current row, column, or box
                if (rows[i].count(num) || cols[j].count(num) || boxes[boxIndex].count(num)) {
                    return false;
                }

                // Add the number to the respective sets
                rows[i].insert(num);
                cols[j].insert(num);
                boxes[boxIndex].insert(num);
            }
        }

        // If no conflicts are found, the board is valid
        return true;
    }
};
