class Solution {
public:
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    void display(vector<vector<int>>& grid) {
        for (auto v : grid) {
            for (int x : v) {
                cout << x << "  ";
            }
            cout << endl;
        }
    }

    bool checkBorder(int x, int y, int m, int n) {
        return x < m && x >= 0 && y < n && y >= 0;
    }
    bool dfs(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> hTracker(m, vector<int>(n));
        priority_queue<pair<int, pair<int, int>>>
            q;
        q.push({grid[0][0], {0, 0}});
        visited[0][0] = 1;
        hTracker[0][0] = health - grid[0][0];
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                auto temp = q.top();
                q.pop();
                for (auto d : dirs) {
                    int nx = d.first + temp.second.first,
                        ny = d.second + temp.second.second;

                    if (checkBorder(nx, ny, m, n) && !visited[nx][ny]) {
                        hTracker[nx][ny] =
                            hTracker[temp.second.first][temp.second.second] -
                            grid[nx][ny];
                        visited[nx][ny] = 1;
                        q.push({hTracker[nx][ny], {nx, ny}});
                    }
                }
            }
        }
        display(hTracker);
        return hTracker[m - 1][n - 1] >= 1;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        return dfs(grid, health);
    }
};