class Solution {
public:
    vector<int> bfs(int index,int curComp, vector<bool>& visited,
             unordered_map<int, vector<int>>& graph) {

        vector<int> comp;
        comp.push_back(index);
        queue<int> q;
        q.push(index);



        visited[index] = true;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            for(int node : graph[temp]){
               if(!visited[node]){
                comp.push_back(node);
                visited[node] = true;
                q.push(node);
               }
            }
        }
        return comp;

    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;
        vector<bool> visited(50, false);
        vector<int> compIndex(50,0);
        unordered_map<int,int>compCount;
        int curComp = 0;

        int result = 0;
        for (auto e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                vector<int> tempComp = bfs(i, curComp,visited, graph);
                bool flag = 1;
                for(int j : tempComp){
                    if(graph[j].size() != tempComp.size()-1){
                       flag = 0;
                       break;
                    }
                }
                result += flag;
            }
        }
        return result;
    }
};