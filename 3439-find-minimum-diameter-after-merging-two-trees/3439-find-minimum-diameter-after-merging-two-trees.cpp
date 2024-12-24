class Solution {
public:


    pair<int, int> bfs(const vector<vector<int>>& tree, int start) {
    int n = tree.size();
    vector<int> dist(n, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    int farthest = start, maxDist = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int neighbor : tree[node]) {
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
                if (dist[neighbor] > maxDist) {
                    maxDist = dist[neighbor];
                    farthest = neighbor;
                }
            }
        }
    }
    return {farthest, maxDist};
}

int treeDiameter(const vector<vector<int>>& tree) {
    auto [farthest, _] = bfs(tree, 0);
    auto [_, diameter] = bfs(tree, farthest);
    return diameter;
}

int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
    int n = edges1.size() + 1, m = edges2.size() + 1;

    // Build adjacency lists
    vector<vector<int>> tree1(n), tree2(m);
    for (const auto& edge : edges1) {
        tree1[edge[0]].push_back(edge[1]);
        tree1[edge[1]].push_back(edge[0]);
    }
    for (const auto& edge : edges2) {
        tree2[edge[0]].push_back(edge[1]);
        tree2[edge[1]].push_back(edge[0]);
    }

    // Calculate diameters of the individual trees
    int diameter1 = treeDiameter(tree1);
    int diameter2 = treeDiameter(tree2);

    // The minimum possible diameter after adding the edge
    return max(diameter1, max(diameter2, (diameter1 + 1) / 2 + (diameter2 + 1) / 2 + 1));
}

};