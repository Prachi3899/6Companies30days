class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> combination;
        backtrack(1, k, n, combination, result);
        return result;
    }

private:
    void backtrack(int start, int k, int n, vector<int>& combination, vector<vector<int>>& result) {
        // Base case: if the combination is valid
        if (combination.size() == k && n == 0) {
            result.push_back(combination);
            return;
        }

        // Explore all numbers from `start` to 9
        for (int i = start; i <= 9; i++) {
            // If adding `i` exceeds the target sum, stop further exploration
            if (i > n) break;

            // Include the current number in the combination
            combination.push_back(i);

            // Recurse with the next number
            backtrack(i + 1, k, n - i, combination, result);

            // Backtrack: remove the last number added
            combination.pop_back();
        }
    }
};
