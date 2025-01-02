class Solution {
public:
    // Helper function to check if an array is strictly increasing
    bool isStrictlyIncreasing(const vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] <= nums[i - 1]) {
                return false;
            }
        }
        return true;
    }

    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        // Iterate over all possible subarrays
        for (int start = 0; start < n; ++start) {
            for (int end = start; end < n; ++end) {
                // Remove the current subarray
                vector<int> remaining;
                for (int i = 0; i < n; ++i) {
                    if (i < start || i > end) {
                        remaining.push_back(nums[i]);
                    }
                }
                // Check if the remaining array is strictly increasing
                if (isStrictlyIncreasing(remaining)) {
                    ++count;
                }
            }
        }

        return count;
    }
};
