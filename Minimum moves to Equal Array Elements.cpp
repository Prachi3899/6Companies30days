class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // Step 1: Sort the array to find the median
        sort(nums.begin(), nums.end());
        
        // Step 2: Find the median
        int median = nums[nums.size() / 2];
        
        // Step 3: Calculate the total moves required
        int moves = 0;
        for (int num : nums) {
            moves += abs(num - median);
        }
        
        return moves;
    }
};
