class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        // Pair of value and index
        vector<pair<int, int>> indexedNums;
        for (int i = 0; i < nums.size(); i++) {
            indexedNums.push_back({nums[i], i});
        }
        
        // Sort by value in descending order
        sort(indexedNums.begin(), indexedNums.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.first > b.first;
        });
        
        // Take the top k elements and store their indices
        vector<int> indices;
        for (int i = 0; i < k; i++) {
            indices.push_back(indexedNums[i].second);
        }
        
        // Sort indices to maintain the original order
        sort(indices.begin(), indices.end());
        
        // Build the result subsequence
        vector<int> result;
        for (int index : indices) {
            result.push_back(nums[index]);
        }
        
        return result;
    }
};
