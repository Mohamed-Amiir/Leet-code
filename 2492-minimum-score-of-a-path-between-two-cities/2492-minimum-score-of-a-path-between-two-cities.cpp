class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int result = 1e9;
        unordered_map<int, vector<pair<int, int>>> graph;
        unordered_map<int, bool> visited;
        for (auto r : roads) {
            graph[r[0]].push_back({r[1], r[2]});
            graph[r[1]].push_back({r[0],r[2]});
        }

        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                auto temp = q.front();
                q.pop();
                vector<pair<int, int>> nighbrs = graph[temp];
                for (auto ni : nighbrs) {
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