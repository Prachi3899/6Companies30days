class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        vector<int> dp(n + 1, 0);

        // Fill dp from the end of the string
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = dp[i + 1] + 1; // Assume current character is extra
            for (int j = i; j < n; ++j) {
                string substring = s.substr(i, j - i + 1);
                if (dict.find(substring) != dict.end()) {
                    dp[i] = min(dp[i], dp[j + 1]);
                }
            }
        }

        return dp[0];
    }
};