class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        int n = s.length();
        
        // dp[i] will be true if s[0...i-1] can be segmented into words in wordDict
        vector<bool> dp(n + 1, false);
        dp[0] = true;  // Empty string can always be segmented
        
        for (int i = 1; i <= n; ++i) {
            // Check all possible previous positions
            for (int j = 0; j < i; ++j) {
                if (dp[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end()) {
                    dp[i] = true;
                    break;  // No need to check further, since we found a valid segmentation
                }
            }
        }
        
        return dp[n];  // If dp[n] is true, then s can be segmented
    }
};