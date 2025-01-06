class Solution {
public:
    int maxProduct(string s) {
        int n = s.size();
        int maxProduct = 0;

        // Function to check if a subsequence (represented by bitmask) is palindromic
        auto isPalindrome = [&](int mask) {
            string subseq = "";
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    subseq += s[i];
                }
            }
            string revSubseq = subseq;
            reverse(revSubseq.begin(), revSubseq.end());
            return subseq == revSubseq;
        };

        // Map to store the maximum length of a palindromic subsequence for a given bitmask
        vector<int> maxLength(1 << n, 0);

        // Calculate the maximum length of palindromic subsequences for all masks
        for (int mask = 0; mask < (1 << n); ++mask) {
            if (isPalindrome(mask)) {
                maxLength[mask] = __builtin_popcount(mask); // Count the number of set bits
            }
        }

        // Iterate through all pairs of masks to find disjoint subsets
        for (int mask1 = 0; mask1 < (1 << n); ++mask1) {
            for (int mask2 = 0; mask2 < (1 << n); ++mask2) {
                if ((mask1 & mask2) == 0) { // Ensure disjoint subsets
                    maxProduct = max(maxProduct, maxLength[mask1] * maxLength[mask2]);
                }
            }
        }

        return maxProduct;
    }
};