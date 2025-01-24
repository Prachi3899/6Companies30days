class Solution {
public:
    const int MOD = 1e9 + 7;
    
    // Helper function for modular exponentiation
    long long modPow(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;  // Ensure base is within mod bounds initially
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod; // Apply modulo in multiplication
            }
            base = (base * base) % mod; // Apply modulo for squaring
            exp /= 2;
        }
        return result;
    }
    
    int minNonZeroProduct(int p) {
        long long maxNum = (1LL << p) - 1; // Largest number (2^p - 1)
        long long secondMax = maxNum - 1; // Second-largest number (2^p - 2)
        long long exp = (1LL << (p - 1)) - 1; // 2^(p-1) - 1
        
        // Compute the minimum product
        long long secondMaxPow = modPow(secondMax, exp, MOD); // Modular exponentiation
        long long minProduct = (secondMaxPow * (maxNum % MOD)) % MOD; // Combine with maxNum
        return (int)minProduct;
    }
};
