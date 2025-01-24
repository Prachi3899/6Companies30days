class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<int> startSet;

        // Step 1: Convert all startWords to bitmasks and store in a set
        for (const string& word : startWords) {
            int bitmask = 0;
            for (char c : word) {
                bitmask |= (1 << (c - 'a'));
            }
            startSet.insert(bitmask);
        }

        int count = 0;

        // Step 2: Check targetWords
        for (const string& word : targetWords) {
            int bitmask = 0;
            for (char c : word) {
                bitmask |= (1 << (c - 'a'));
            }

            // Try removing each bit and check if it exists in startSet
            for (char c : word) {
                int reducedBitmask = bitmask & ~(1 << (c - 'a'));
                if (startSet.count(reducedBitmask)) {
                    count++;
                    break;
                }
            }
        }

        return count;
    }
};
