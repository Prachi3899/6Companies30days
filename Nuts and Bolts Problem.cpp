class Solution {
public:
    void matchPairs(int n, char nuts[], char bolts[]) {
        // Define the order
        std::string order = "!#$%&*?@^";
        std::unordered_map<char, int> charOrder;
        
        // Create a mapping of characters to their positions in the order
        for (int i = 0; i < order.size(); ++i) {
            charOrder[order[i]] = i;
        }

        // Custom comparator using the order mapping
        auto comparator = [&](char a, char b) {
            return charOrder[a] < charOrder[b];
        };

        // Sort both arrays using the custom comparator
        std::sort(nuts, nuts + n, comparator);
        std::sort(bolts, bolts + n, comparator);
    }
};