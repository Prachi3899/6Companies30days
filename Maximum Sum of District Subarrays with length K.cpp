class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq; // Frequency map to track element occurrences
        long long maxSum = 0, currentSum = 0;
        int start = 0; // Start of the sliding window

        for (int end = 0; end < nums.size(); ++end) {
            currentSum += nums[end];
            freq[nums[end]]++;

            // If the window size exceeds k or has duplicate elements
            while (freq[nums[end]] > 1 || end - start + 1 > k) {
                freq[nums[start]]--;
                currentSum -= nums[start];
                start++;
            }

            // If the current window size is exactly k, update maxSum
            if (end - start + 1 == k) {
                maxSum = max(maxSum, currentSum);
            }
        }

        return maxSum;
    }
};