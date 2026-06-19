class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int result = 0, n = grid.size();
        if (grid[0][0] || grid[n - 1][n - 1])
            return -1;
        if(n == 1)return 1;
        vector<vector<int>> visited(n,vector<int>(n,0));
        vector<pair<int, int>> dirs = {{0, 1},  {1, 0},  {0, -1},  {-1, 0},
                                       {1, -1}, {-1, 1}, {-1, -1}, {1, 1}};
        queue<vector<int>> q;
        q.push({0, 0, 1});
        visited[0][0] = 1;
        while (!q.empty()) {
            vector<int> temp = q.front();
            q.pop();
            for (auto d : dirs) {
                int x = temp[0] + d.first, y = temp[1] + d.second;
                if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 0 &&
                    visited[x][y] == 0) {
                    int newDist = temp[2] + 1;
                    visited[x][y] = 1;
                    q.push({x, y, newDist});
                    if (x == n - 1 && y == n - 1)
                        return newDist;
                }
            }
        }
        return -1;
    }
};