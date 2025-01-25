class Solution {
public:
    int numberOfGoodSubsets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        vector<int> count(31, 0);
        for (int num : nums) count[num]++;
        
        // List of all primes ≤ 30
        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        
        // Precompute prime masks for numbers 1 to 30
        vector<int> primeMask(31, 0);
        for (int i = 2; i <= 30; i++) {
            int mask = 0;
            int x = i;
            bool valid = true;
            for (int j = 0; j < primes.size(); j++) {
                int prime = primes[j];
                if (x % prime == 0) {
                    mask |= (1 << j);
                    x /= prime;
                    if (x % prime == 0) { // Invalid if prime factor repeats
                        valid = false;
                        break;
                    }
                }
            }
            if (valid) primeMask[i] = mask;
        }
        
        // DP array for subset counts
        vector<int> dp(1 << primes.size(), 0);
        dp[0] = 1; // Base case: empty subset
        
        for (int i = 2; i <= 30; i++) {
            if (count[i] == 0 || primeMask[i] == 0) continue;
            
            // Update DP from back to front to avoid overwriting
            for (int mask = (1 << primes.size()) - 1; mask >= 0; mask--) {
                if ((mask & primeMask[i]) == 0) { // If no conflict in prime factors
                    dp[mask | primeMask[i]] = (dp[mask | primeMask[i]] + (long long)dp[mask] * count[i]) % MOD;
                }
            }
        }
        
        // Sum up all good subsets
        int result = 0;
        for (int mask = 1; mask < (1 << primes.size()); mask++) {
            result = (result + dp[mask]) % MOD;
        }
        
        // Account for `1`s in the input
        if (count[1] > 0) {
            long long pow1 = 1;
            for (int i = 0; i < count[1]; i++) {
                pow1 = (pow1 * 2) % MOD;
            }
            result = (result * pow1) % MOD;
        }
        
        return result;
    }
};
