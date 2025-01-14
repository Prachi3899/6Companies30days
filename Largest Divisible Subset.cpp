class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};
        
        // Step 1: Sort the array
        sort(nums.begin(), nums.end());
        
        // Step 2: DP initialization
        vector<int> dp(n, 1);  // dp[i] = size of the largest subset ending at nums[i]
        vector<int> parent(n, -1); // parent[i] = index of the previous element in the subset
        int maxSize = 0; // Size of the largest subset
        int maxIndex = -1; // Index of the last element in the largest subset
        
        // Step 3: Fill dp and parent
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            // Update maximum subset size
            if (dp[i] > maxSize) {
                maxSize = dp[i];
                maxIndex = i;
            }
        }
        
        // Step 4: Reconstruct the subset
        vector<int> result;
        for (int i = maxIndex; i != -1; i = parent[i]) {
            result.push_back(nums[i]);
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};