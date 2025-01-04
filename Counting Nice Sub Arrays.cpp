class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0, oddCount = 0;
        unordered_map<int, int> prefixCount; // Tracks counts of prefix sums
        prefixCount[0] = 1; // Base case: 0 odd numbers initially

        for (int num : nums) {
            // Increment oddCount if the current number is odd
            oddCount += (num % 2 == 1);

            // Check if there's a prefix with oddCount - k
            if (prefixCount.find(oddCount - k) != prefixCount.end()) {
                count += prefixCount[oddCount - k];
            }

            // Update the prefix count
            prefixCount[oddCount]++;
        }

        return count;
    }
};
