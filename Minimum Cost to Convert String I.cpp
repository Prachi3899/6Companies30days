class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const int INF = 1e9;
        int n = 26;
        vector<vector<int>> dist(n, vector<int>(n, INF));
        
        // Initialize distances: cost to transform a character into itself is 0
        for (int i = 0; i < n; ++i) {
            dist[i][i] = 0;
        }
        
        // Add edges for transformations from original to changed
        for (int i = 0; i < original.size(); ++i) {
            int from = original[i] - 'a';
            int to = changed[i] - 'a';
            dist[from][to] = min(dist[from][to], cost[i]);
        }
        
        // Floyd-Warshall Algorithm to calculate shortest paths between all pairs of nodes
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][k] < INF && dist[k][j] < INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        
        // Calculate total cost to transform source into target
        long long totalCost = 0;
        for (int i = 0; i < source.size(); ++i) {
            int from = source[i] - 'a';
            int to = target[i] - 'a';
            if (dist[from][to] == INF) {
                return -1; // Transformation not possible
            }
            totalCost += dist[from][to];
        }
        
        return totalCost;
    }
};