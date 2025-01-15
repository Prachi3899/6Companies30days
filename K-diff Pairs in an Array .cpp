class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0; // Absolute difference cannot be negative

        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }

        int count = 0;
        for (auto& [num, freq] : freqMap) {
            if (k == 0) {
                // Count pairs (x, x) where x appears more than once
                if (freq > 1) {
                    count++;
                }
            } else {
                // Count pairs (x, x + k)
                if (freqMap.count(num + k)) {
                    count++;
                }
            }
        }

        return count;
    }
};
