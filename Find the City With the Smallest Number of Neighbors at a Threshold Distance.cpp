class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Initialize distance matrix with infinity
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        // Distance from a city to itself is 0
        for (int i = 0; i < n; ++i) {
            dist[i][i] = 0;
        }

        // Fill initial distances based on the edges
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], weight = edge[2];
            dist[u][v] = weight;
            dist[v][u] = weight;
        }

        // Floyd-Warshall algorithm to compute all-pairs shortest paths
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        // Determine the city with the smallest number of reachable cities
        int minReachable = INT_MAX;
        int resultCity = -1;

        for (int i = 0; i < n; ++i) {
            int reachableCount = 0;
            for (int j = 0; j < n; ++j) {
                if (dist[i][j] <= distanceThreshold) {
                    ++reachableCount;
                }
            }

            // Update result based on criteria
            if (reachableCount < minReachable || 
                (reachableCount == minReachable && i > resultCity)) {
                minReachable = reachableCount;
                resultCity = i;
            }
        }

        return resultCity;
    }
};