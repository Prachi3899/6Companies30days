class Solution {
public:
    int squareFreeSubsets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        unordered_map<int, int> primeMask; // Map number to its prime factorization bitmask
        
        // Precompute the prime masks for numbers 1 to 30
        for (int i = 1; i <= 30; ++i) {
            int mask = 0;
            bool squareFree = true;
            for (int j = 0; j < primes.size(); ++j) {
                int p = primes[j];
                if (i % (p * p) == 0) { // Divisible by square of prime
                    squareFree = false;
                    break;
                }
                if (i % p == 0) {
                    mask |= (1 << j);
                }
            }
            if (squareFree) {
                primeMask[i] = mask;
            }
        }

        // Count the occurrences of each number in the array
        vector<int> count(31, 0);
        for (int num : nums) {
            ++count[num];
        }

        // DP to count subsets
        vector<int> dp(1 << primes.size(), 0); // DP for bitmasks of prime factors
        dp[0] = 1; // Base case: empty subset
        
        for (int i = 2; i <= 30; ++i) {
            if (count[i] > 0 && primeMask.count(i)) {
                int mask = primeMask[i];
                for (int j = (1 << primes.size()) - 1; j >= 0; --j) {
                    if ((j & mask) == 0) { // No overlapping prime factors
                        dp[j | mask] = (dp[j | mask] + (long long)dp[j] * count[i]) % MOD;
                    }
                }
            }
        }

        // Sum all valid subsets
        int result = 0;
        for (int val : dp) {
            result = (result + val) % MOD;
        }

        // Handle subsets formed by 1s
        if (count[1] > 0) {
            result = (long long)result * powMod(2, count[1], MOD) % MOD;
        }

        return (result - 1 + MOD) % MOD; // Exclude the empty subset
    }

private:
    int powMod(int base, int exp, int mod) {
        long long result = 1, b = base;
        while (exp > 0) {
            if (exp & 1) {
                result = (result * b) % mod;
            }
            b = (b * b) % mod;
            exp >>= 1;
        }
        return result;
    }
};