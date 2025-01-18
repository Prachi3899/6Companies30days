class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        int result = 0; // To store the final count of good pairs
        dfs(root, distance, result);
        return result;
    }

private:
    vector<int> dfs(TreeNode* node, int distance, int& result) {
        if (!node) return vector<int>(distance + 1, 0);

        if (!node->left && !node->right) {
            // Leaf node: return a distance array with 1 leaf at depth 1
            vector<int> leafDistances(distance + 1, 0);
            leafDistances[1] = 1;
            return leafDistances;
        }

        // Recursively compute distances for left and right subtrees
        vector<int> leftDistances = dfs(node->left, distance, result);
        vector<int> rightDistances = dfs(node->right, distance, result);

        // Count good pairs from left and right distances
        for (int i = 1; i <= distance; ++i) {
            for (int j = 1; j <= distance; ++j) {
                if (i + j <= distance) {
                    result += leftDistances[i] * rightDistances[j];
                }
            }
        }

        // Prepare the current node's distance array
        vector<int> currentDistances(distance + 1, 0);
        for (int i = 1; i < distance; ++i) {
            if (i + 1 <= distance) {
                currentDistances[i + 1] += leftDistances[i] + rightDistances[i];
            }
        }

        return currentDistances;
    }
};
