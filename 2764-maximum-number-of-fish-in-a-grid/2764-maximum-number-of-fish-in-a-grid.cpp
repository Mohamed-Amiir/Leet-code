
class Solution {
public:
int dfs(vector<vector<int>>& grid, int r, int c, int dirs[4][2]) {
        int m = grid.size();
        int n = grid[0].size();

        // Check if the current cell is out of bounds or is not a water cell
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0) {
            return 0;
        }

        // Collect the fish from the current cell
        int fish = grid[r][c];
        grid[r][c] = 0; // Mark the cell as visited by setting it to 0

        // Explore all adjacent cells using a traditional for loop
        for (int i = 0; i < 4; ++i) {
            int nr = r + dirs[i][0];
            int nc = c + dirs[i][1];
            fish += dfs(grid, nr, nc, dirs);
        }

        return fish;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        int maxFish = 0;

        // Directions for moving to adjacent cells
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Iterate through each cell in the grid
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    // Start DFS from this cell
                    int currentFish = dfs(grid, i, j, dirs);
                    maxFish = max(maxFish, currentFish);
                }
            }
        }

        return maxFish;
    }

    
};