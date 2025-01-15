class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        int count = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'X') {
                    // Check if it's the start of a battleship
                    if ((i == 0 || board[i - 1][j] != 'X') && 
                        (j == 0 || board[i][j - 1] != 'X')) {
                        ++count;
                    }
                }
            }
        }

        return count;
    }

};