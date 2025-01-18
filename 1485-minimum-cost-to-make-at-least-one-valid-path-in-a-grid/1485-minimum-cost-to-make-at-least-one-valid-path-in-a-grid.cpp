class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
        queue<tuple<int, int, int>> q; // (x, y, cost)
        
        // Start BFS from (0, 0)
        q.push({0, 0, 0});
        cost[0][0] = 0;

        while (!q.empty()) {
            auto [x, y, currCost] = q.front();
            q.pop();

            // Check all four directions
            for (int d = 0; d < 4; ++d) {
                int nx = x + directions[d][0];
                int ny = y + directions[d][1];
                int newCost = currCost + (grid[x][y] != d + 1);

                // Check bounds and whether this is a cheaper way to reach (nx, ny)
                if (nx >= 0 && ny >= 0 && nx < m && ny < n && newCost < cost[nx][ny]) {
                    cost[nx][ny] = newCost;
                    q.push({nx, ny, newCost});
                }
            }
        }

        return cost[m-1][n-1];
    }
};
