class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size();
        set<vector<int>> distinctSubarrays;

        // Iterate over all possible starting points
        for (int i = 0; i < n; i++) {
            vector<int> subarray;
            int divisibleCount = 0;

            // Expand the window from `i` to `j`
            for (int j = i; j < n; j++) {
                subarray.push_back(nums[j]);
                if (nums[j] % p == 0) {
                    divisibleCount++;
                }

                // Break if the count of divisible numbers exceeds `k`
                if (divisibleCount > k) {
                    break;
                }

                // Add the current subarray to the set
                distinctSubarrays.insert(subarray);
            }
        }

        // Return the number of distinct subarrays
        return distinctSubarrays.size();
    }
};
