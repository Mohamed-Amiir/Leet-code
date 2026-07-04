class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int result = 1e9;
        unordered_map<int, vector<pair<int, int>>> graph;
        vector<bool> visited(n,false);
        for (auto r : roads) {
            graph[r[0]].push_back({r[1], r[2]});
            graph[r[1]].push_back({r[0],r[2]});
        }

        queue<int> q;
        q.push(1);
        visited[1] = true;
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                auto temp = q.front();
                q.pop();
                vector<pair<int, int>> nighbrs = graph[temp];
                for (pair<int,int> ni : graph[temp]) {
                    result = min(result, ni.second);
                    if (!visited[ni.first]) {
                        q.push(ni.first);
                        visited[ni.first] = 1;
                    }
                }
            }
        }
        return result;
    }
};