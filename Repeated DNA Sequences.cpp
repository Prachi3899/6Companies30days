class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> seen;
        unordered_set<string> repeated;
        vector<string> result;

        // Traverse the string with a sliding window of size 10
        for (int i = 0; i + 9 < s.size(); ++i) {
            string substring = s.substr(i, 10); // Extract 10-character substring

            if (seen.count(substring)) {
                repeated.insert(substring); // Add to repeated set if already seen
            } else {
                seen.insert(substring); // Add to seen set if new
            }
        }

        // Collect all repeated substrings into the result vector
        result.assign(repeated.begin(), repeated.end());
        return result;
    }
};
