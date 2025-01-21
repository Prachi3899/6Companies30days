class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        // Build the adjacency list for the tree
        vector<vector<int>> graph(n);
        for (const auto& edge : edges) {
            int u = edge[0] - 1, v = edge[1] - 1;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        // Function to calculate the diameter of a subtree represented by a mask
        auto calculateDiameter = [&](int mask) -> int {
            vector<int> nodes;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) nodes.push_back(i);
            }

            // Check connectivity
            queue<int> q;
            unordered_set<int> visited;
            q.push(nodes[0]);
            visited.insert(nodes[0]);

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int neighbor : graph[node]) {
                    if ((mask & (1 << neighbor)) && !visited.count(neighbor)) {
                        visited.insert(neighbor);
                        q.push(neighbor);
                    }
                }
            }

            // If not all nodes are connected, return -1
            if (visited.size() != nodes.size()) return -1;

            // BFS to find the diameter
            auto bfs = [&](int start) -> pair<int, int> {
                queue<int> q;
                vector<int> dist(n, -1);
                q.push(start);
                dist[start] = 0;

                int farthestNode = start, maxDist = 0;
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (int neighbor : graph[node]) {
                        if ((mask & (1 << neighbor)) && dist[neighbor] == -1) {
                            dist[neighbor] = dist[node] + 1;
                            q.push(neighbor);
                            if (dist[neighbor] > maxDist) {
                                maxDist = dist[neighbor];
                                farthestNode = neighbor;
                            }
                        }
                    }
                }
                return {farthestNode, maxDist};
            };

            // Find one endpoint of the diameter
            auto [farthestNode, _] = bfs(nodes[0]);
            // Find the other endpoint and the diameter length
            auto [_, diameter] = bfs(farthestNode);
            return diameter;
        };

        vector<int> result(n - 1, 0);

        // Enumerate all subsets using bitmasking
        for (int mask = 1; mask < (1 << n); ++mask) {
            int diameter = calculateDiameter(mask);
            if (diameter > 0 && diameter < n) {
                result[diameter - 1]++;
            }
        }

        return result;
    }
};
