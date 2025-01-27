class Solution {
public:
    const int MOD = 1e9 + 7;

    // Function to compute factorial % MOD
    long long modFactorial(int n, vector<long long>& fact) {
        if (fact[n] != -1) return fact[n];
        fact[n] = (n * modFactorial(n - 1, fact)) % MOD;
        return fact[n];
    }

    // Function to compute modular inverse using Fermat's Little Theorem
    long long modInverse(long long a, long long m) {
        long long res = 1, exp = m - 2;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * a) % m;
            a = (a * a) % m;
            exp /= 2;
        }
        return res;
    }

    // Function to compute nCr % MOD
    long long nCr(int n, int r, vector<long long>& fact) {
        if (r > n || r < 0) return 0;
        long long num = fact[n];
        long long denom = (fact[r] * fact[n - r]) % MOD;
        return (num * modInverse(denom, MOD)) % MOD;
    }

    int numberOfWays(int startPos, int endPos, int k) {
        int d = abs(endPos - startPos);
        // Check feasibility
        if (k < d || (k - d) % 2 != 0) return 0;

        int rightSteps = (k + d) / 2; // Derived from the equations above

        // Precompute factorials up to k
        vector<long long> fact(k + 1, -1);
        fact[0] = 1;
        modFactorial(k, fact);

        // Calculate the number of ways
        return nCr(k, rightSteps, fact);
    }
};
