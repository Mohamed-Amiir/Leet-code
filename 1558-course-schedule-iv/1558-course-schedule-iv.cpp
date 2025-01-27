class Solution {
public:
    void DFS(int start, int current, vector<vector<int>>& graph, vector<unordered_set<int>>& reachable) {
        // Mark the current node as reachable from the start node
        reachable[start].insert(current);

        // Explore all neighbors
        for (int neighbor : graph[current]) {
            if (!reachable[start].count(neighbor)) {
                DFS(start, neighbor, graph, reachable);
            }
        }
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // Step 1: Build the graph
        vector<vector<int>> graph(numCourses);
        for (const auto& edge : prerequisites) {
            graph[edge[0]].push_back(edge[1]);
        }

        // Step 2: Compute transitive closure using DFS
        vector<unordered_set<int>> reachable(numCourses);
        for (int i = 0; i < numCourses; i++) {
            DFS(i, i, graph, reachable);
        }

        // Step 3: Answer the queries
        vector<bool> result;
        for (const auto& query : queries) {
            int u = query[0], v = query[1];
            if (reachable[u].count(v)) {
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        }

        return result;
    }


};