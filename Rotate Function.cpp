class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Calculate F(0) and the sum of the array.
        int sum = 0, F0 = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            F0 += i * nums[i];
        }
        
        // Step 2: Initialize the maximum value of F(k) with F(0).
        int maxF = F0;
        
        // Step 3: Calculate F(k) for all k from 1 to n-1 using the recurrence relation.
        int currentF = F0;
        for (int k = 1; k < n; ++k) {
            currentF = currentF + sum - n * nums[n - k];
            maxF = max(maxF, currentF);
        }
        
        return maxF;
    }
};