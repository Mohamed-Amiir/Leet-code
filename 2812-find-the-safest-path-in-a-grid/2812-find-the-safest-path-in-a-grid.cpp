class Solution {
public:
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    bool checkPorder(int x, int y, int n) {
        return x >= 0 && x < n && y >= 0 && y < n;
    }
    vector<vector<int>> bfs(vector<vector<int>>& grid, queue<pair<int, int>>& q,
                            vector<vector<bool>>& visited) {
        int result = 0;
        int levels = 0;
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n));
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                auto temp = q.front();
                q.pop();
                for (auto d : dirs) {
                    int nx = temp.first + d.first;
                    int ny = temp.second + d.second;
                    if (checkPorder(nx, ny, n) && !visited[nx][ny]) {
                        visited[nx][ny] = 1;
                        dist[nx][ny] = levels+1;
                        q.push({nx, ny});
                    }
                }
            }
            levels++;
        }
        return dist;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        queue<pair<int, int>> ones;
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    visited[i][j] = 1;
                    ones.push({i, j});
                }
            }
        }

        vector<vector<int>> dist = bfs(grid, ones, visited);
        vector<vector<int>> best(n, vector<int>(n, -1));

        priority_queue<pair<int, pair<int, int>>> pq;

        best[0][0] = dist[0][0];
        pq.push({dist[0][0], {0, 0}});

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            int safety = cur.first;
            int x = cur.second.first;
            int y = cur.second.second;

            if (safety < best[x][y])
                continue;

            if (x == n - 1 && y == n - 1)
                return safety;

            for (auto d : dirs) {
                int nx = x + d.first;
                int ny = y + d.second;

                if (!checkPorder(nx, ny, n))
                    continue;

                int newSafety = min(safety, dist[nx][ny]);

                if (newSafety > best[nx][ny]) {
                    best[nx][ny] = newSafety;
                    pq.push({newSafety, {nx, ny}});
                }
            }
        }

        return 0;
    }
};