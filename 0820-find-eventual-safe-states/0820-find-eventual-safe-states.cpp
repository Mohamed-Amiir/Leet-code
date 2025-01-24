class Solution {
public:
    bool DFS(int x, vector<vector<int>>& graph, vector<bool>& visited,
             vector<int>& result, vector<bool>& terminal) 
    {
        if (terminal[x] == 1) {
            return 1;
        } else if (visited[x]) {
            return 0;
        }
        visited[x] = 1;

        for (int a : graph[x]) {

            if(!DFS(a, graph, visited, result, terminal)){
               return false;
            }
        }

        terminal[x] = 1;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> terminal(n, 0), visited(n, 0);
        vector<int> result;

        for (int i = 0; i < n; i++) {
            if (graph[i].size() == 0) {
                terminal[i] = 1;
                visited[i] = 1;
            } 
            else{
              bool dummy =  DFS(i, graph, visited, result,terminal);
            }
            
        }

        for (int i = 0; i < n; i++)
            if (terminal[i] == 1)
                result.push_back(i);
        return result;
    }
};