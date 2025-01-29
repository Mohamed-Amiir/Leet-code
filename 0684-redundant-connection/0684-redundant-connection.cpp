class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1); // 1-based indexing for nodes
        for (int i = 1; i <= n; i++) {
            parent[i] = i; // Initialize each node as its own parent
        }

        // Find function with path compression
        function<int(int)> find = [&](int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]); // Path compression
            }
            return parent[x];
        };

        // Iterate through all edges
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            int rootU = find(u), rootV = find(v);
            if (rootU == rootV) {
                // If u and v are already connected, this edge is redundant
                return edge;
            } else {
                // Union the two nodes
                parent[rootV] = rootU;
            }
        }

        return {}; // No redundant edge found (should not happen as per problem constraints)
    }
};