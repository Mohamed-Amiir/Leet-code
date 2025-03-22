class Solution {
public:
    void BFS(int x, int& result, unordered_map<int, vector<int>>& graph,
             unordered_map<int, bool>& visited) {
        vector<int> neighbors;
        visited[x] = true;
        queue<int> q;
        q.push(x);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            neighbors.push_back(cur);
            for (auto n : graph[cur]) {
                if (!visited[n]) {
                    visited[n] = true;
                    q.push(n);
                }
            }
        }
        bool flag = 1;
        for (auto y : neighbors) {
            if (graph[y].size() != neighbors.size() - 1) {
                flag = 0;
                break;
            }
        }
        if (flag)
            result++;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, bool> visited;
        int result = 0, nodes = 0;
        for (auto x : edges) {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        for (int i = 0; i < n; i++) {
            BFS(i, result, graph, visited);
        }
        return result;
    }
};