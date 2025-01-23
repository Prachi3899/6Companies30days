class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> a_indices, b_indices, result;

        // Step 1: Find all indices where substring a matches
        for (int i = 0; i <= int(s.size()) - int(a.size()); i++) {
            if (s.substr(i, a.size()) == a) {
                a_indices.push_back(i);
            }
        }

        // Step 2: Find all indices where substring b matches
        for (int i = 0; i <= int(s.size()) - int(b.size()); i++) {
            if (s.substr(i, b.size()) == b) {
                b_indices.push_back(i);
            }
        }

        // Step 3: Use two pointers to find "beautiful" indices
        int j = 0;
        for (int i : a_indices) {
            // Move the pointer in b_indices to ensure |j - i| <= k
            while (j < b_indices.size() && b_indices[j] < i - k) {
                j++;
            }
            // Check if there is a valid j where |j - i| <= k
            if (j < b_indices.size() && abs(b_indices[j] - i) <= k) {
                result.push_back(i);
            }
        }

        return result;
    }
};
