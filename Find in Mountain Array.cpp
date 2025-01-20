class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        // Find the peak of the mountain array
        int left = 0, right = n - 1, peak = -1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                left = mid + 1; // Peak is to the right
            } else {
                right = mid; // Peak is to the left or at mid
            }
        }
        peak = left;

        // Binary search on the increasing part
        auto binarySearch = [&](int l, int r, bool increasing) -> int {
            while (l <= r) {
                int mid = l + (r - l) / 2;
                int value = mountainArr.get(mid);
                if (value == target) return mid;
                if (value < target) {
                    l = increasing ? mid + 1 : l; // Move right if increasing
                    r = increasing ? r : mid - 1; // Move left if decreasing
                } else {
                    r = increasing ? mid - 1 : r; // Move left if increasing
                    l = increasing ? l : mid + 1; // Move right if decreasing
                }
            }
            return -1;
        };

        // Search in the left (increasing) part
        int result = binarySearch(0, peak, true);
        if (result != -1) return result;

        // Search in the right (decreasing) part
        result = binarySearch(peak + 1, n - 1, false);
        return result;
    }
};
