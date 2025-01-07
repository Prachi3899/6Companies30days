class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return 0;

        int maxLength = 0;

        for (int i = 1; i < n - 1; ++i) {
            // Check if arr[i] is a peak
            if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) {
                int left = i - 1;
                int right = i + 1;

                // Expand left
                while (left > 0 && arr[left - 1] < arr[left]) {
                    --left;
                }

                // Expand right
                while (right < n - 1 && arr[right] > arr[right + 1]) {
                    ++right;
                }

                // Calculate the mountain length
                int mountainLength = right - left + 1;
                maxLength = std::max(maxLength, mountainLength);
            }
        }

        return maxLength;
    }
};
