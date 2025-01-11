class Solution {
public:
    string matrixChainOrder(vector<int>& arr) {
        int n = arr.size() - 1; // Number of matrices
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<vector<int>> bracket(n, vector<int>(n, -1));

        // Fill dp table
        for (int len = 2; len <= n; ++len) { // len is the chain length
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                for (int k = i; k < j; ++k) {
                    int cost = dp[i][k] + dp[k + 1][j] + arr[i] * arr[k + 1] * arr[j + 1];
                    if (cost < dp[i][j]) {
                        dp[i][j] = cost;
                        bracket[i][j] = k;
                    }
                }
            }
        }

        // Generate the result string using the bracket table
        return constructOptimalOrder(bracket, 0, n - 1, 'A');
    }

private:
    string constructOptimalOrder(vector<vector<int>>& bracket, int i, int j, char base) {
        if (i == j) return string(1, base + i); // Single matrix, return its label

        string left = constructOptimalOrder(bracket, i, bracket[i][j], base);
        string right = constructOptimalOrder(bracket, bracket[i][j] + 1, j, base);

        return "(" + left + right + ")";
    }
};