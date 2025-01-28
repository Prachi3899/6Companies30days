class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;
        vector<int> dp(n + 1, 0);
        dp[1] = 1; // On day 1, one person knows the secret

        int totalSharing = 0; // Tracks the total number of sharers

        for (int i = 2; i <= n; ++i) {
            // Add new sharers from day `i - delay`
            if (i - delay >= 1) {
                totalSharing = (totalSharing + dp[i - delay]) % MOD;
            }
            // Remove sharers who forget the secret after `forget` days
            if (i - forget >= 1) {
                totalSharing = (totalSharing - dp[i - forget] + MOD) % MOD;
            }
            // The current day's new sharers are `totalSharing`
            dp[i] = totalSharing;
        }

        // Sum up the people who still remember the secret on the last day
        int result = 0;
        for (int i = n - forget + 1; i <= n; ++i) {
            if (i >= 1) {
                result = (result + dp[i]) % MOD;
            }
        }

        return result;
    }
};
