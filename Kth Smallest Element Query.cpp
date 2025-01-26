class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> result;

        for (const auto& query : queries) {
            int k = query[0];
            int trim = query[1];

            // Create a vector of pairs (trimmed number, index)
            vector<pair<string, int>> trimmedNums;
            for (int i = 0; i < nums.size(); ++i) {
                string trimmed = nums[i].substr(nums[i].size() - trim);
                trimmedNums.emplace_back(trimmed, i);
            }

            // Sort by trimmed number, and by index for ties
            sort(trimmedNums.begin(), trimmedNums.end());

            // Add the index of the k-th smallest trimmed number to the result
            result.push_back(trimmedNums[k - 1].second);
        }

        return result;
    }
};
