class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());

        int mid = (n + 1) / 2; // Middle index for the first half
        int j = mid - 1;       // Pointer for the smaller half
        int k = n - 1;         // Pointer for the larger half

        // Rearrange using virtual indexing
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                nums[i] = sorted[j--]; // Take the largest from the smaller half
            } else {
                nums[i] = sorted[k--]; // Take the largest from the larger half
            }
        }
    }
};
