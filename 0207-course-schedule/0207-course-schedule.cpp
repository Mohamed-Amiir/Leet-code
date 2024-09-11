class Solution {
public:
    bool DFS(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& recStack) {

        visited[node] = true;
        recStack[node] = true;

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                if (DFS(neighbor, graph, visited, recStack)) {
                    return true;
                }
            }
            else if (recStack[neighbor]) {
                return true; 
            }
        }

        recStack[node] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> graph(numCourses);
        for (auto& p : prerequisites) {
            graph[p[1]].push_back(p[0]); 
        }

        vector<bool> visited(numCourses, false);
        vector<bool> recStack(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (DFS(i, graph, visited, recStack)) {
                    return false; 
                }
            }
        }

        return true; 
    }
};