class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // build graph
        for (auto& v : prerequisites) {
            adj[v[1]].push_back(v[0]);
            indegree[v[0]]++;
        }

        queue<int> q;

        // كل اللي indegree = 0
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> result;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            result.push_back(u);

            for (int v : adj[u]) {
                if (--indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        if (result.size() != numCourses)
            return {};

        return result;
    }
};