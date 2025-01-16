class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> adjList; // adjacency list for graph representation
        buildGraph(root, nullptr, adjList);     // Build the adjacency list

        queue<int> q; // BFS queue
        unordered_set<int> visited; // Track visited nodes
        q.push(start);
        visited.insert(start);

        int time = -1; // Tracks time in minutes
        while (!q.empty()) {
            int size = q.size();
            ++time;
            for (int i = 0; i < size; ++i) {
                int node = q.front();
                q.pop();
                for (int neighbor : adjList[node]) {
                    if (!visited.count(neighbor)) {
                        visited.insert(neighbor);
                        q.push(neighbor);
                    }
                }
            }
        }

        return time;
    }

private:
    void buildGraph(TreeNode* node, TreeNode* parent, unordered_map<int, vector<int>>& adjList) {
        if (!node) return;
        if (parent) {
            adjList[node->val].push_back(parent->val);
            adjList[parent->val].push_back(node->val);
        }
        buildGraph(node->left, node, adjList);
        buildGraph(node->right, node, adjList);
    }
};