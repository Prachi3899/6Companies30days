class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        // Sort arr2 for efficient range checking
        sort(arr2.begin(), arr2.end());
        int count = 0;

        for (int num : arr1) {
            // Calculate the valid range [num - d, num + d]
            int low = num - d;
            int high = num + d;

            // Use binary search to check if any value in arr2 falls within the range
            auto it = lower_bound(arr2.begin(), arr2.end(), low);
            if (it == arr2.end() || *it > high) {
                // No element in arr2 within the range
                count++;
            }
        }

        return count;
    }
};
