class Solution {
public:
    vector<int> findTwoElement(vector<int> &arr) {
        int n = arr.size();
        int repeating = -1, missing = -1;

        // Step 1: Swap elements to their correct index
        for (int i = 0; i < n; i++) {
            while (arr[i] != arr[arr[i] - 1]) {
                swap(arr[i], arr[arr[i] - 1]);
            }
        }

        // Step 2: Find the missing and repeating numbers
        for (int i = 0; i < n; i++) {
            if (arr[i] != i + 1) {
                repeating = arr[i];  // The number that appears twice
                missing = i + 1;     // The missing number
                break;
            }
        }

        return {repeating, missing};
    }
};