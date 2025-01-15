class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // Step 1: Count frequencies
        unordered_map<string, int> freqMap;
        for (const string& word : words) {
            freqMap[word]++;
        }

        // Step 2: Use a custom comparator for sorting
        auto comparator = [](const pair<string, int>& a, const pair<string, int>& b) {
            if (a.second == b.second) {
                return a.first < b.first; // Lexicographical order
            }
            return a.second > b.second; // Higher frequency first
        };

        // Create a vector of pairs from the map
        vector<pair<string, int>> freqVec(freqMap.begin(), freqMap.end());
        sort(freqVec.begin(), freqVec.end(), comparator);

        // Step 3: Extract the top k words
        vector<string> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(freqVec[i].first);
        }

        return result;
    }
};
