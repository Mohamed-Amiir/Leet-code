

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        
        // Initialize the heights matrix
        vector<vector<int>> height(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        
        // Mark water cells with height 0 and add them to the queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    height[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        // Directions for adjacent cells (north, east, south, west)
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // Perform BFS
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            int i = curr.first;
            int j = curr.second;
            
            // Explore adjacent cells
            for (auto& dir : dirs) {
                int x = i + dir[0];
                int y = j + dir[1];
                
                // Check if the cell is within bounds and unassigned
                if (x >= 0 && x < m && y >= 0 && y < n && height[x][y] == -1) {
                    height[x][y] = height[i][j] + 1;
                    q.push({x, y});
                }
            }
        }
        
        return height;
    }
};