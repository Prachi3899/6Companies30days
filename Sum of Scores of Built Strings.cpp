class Solution {
public:
    long long sumScores(string s) {
        int n = s.size();
        vector<int> Z(n, 0);

        // Compute the Z-array
        int l = 0, r = 0;
        for (int i = 1; i < n; ++i) {
            if (i <= r) {
                Z[i] = min(r - i + 1, Z[i - l]);
            }
            while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]]) {
                ++Z[i];
            }
            if (i + Z[i] - 1 > r) {
                l = i;
                r = i + Z[i] - 1;
            }
        }

        // Sum the scores
        long long totalScore = n; // Z[0] is n, which corresponds to s == sn
        for (int i = 1; i < n; ++i) {
            totalScore += Z[i];
        }

        return totalScore;
    }
};
