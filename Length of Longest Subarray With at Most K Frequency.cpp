class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;  // To store the frequency of elements in the current window
        int left = 0, maxLength = 0;

        for (int right = 0; right < nums.size(); ++right) {
            freq[nums[right]]++;

            // Shrink the window if any frequency exceeds k
            while (freq[nums[right]] > k) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }
                left++;
            }

            // Update the maximum length of the valid subarray
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};