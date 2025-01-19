class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) return 0;

        int m = heightMap.size();
        int n = heightMap[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap;

        // Push all boundary cells into the priority queue
        for (int i = 0; i < m; ++i) {
            for (int j : {0, n - 1}) {
                minHeap.push({heightMap[i][j], {i, j}});
                visited[i][j] = true;
            }
        }
        for (int j = 0; j < n; ++j) {
            for (int i : {0, m - 1}) {
                if (!visited[i][j]) {
                    minHeap.push({heightMap[i][j], {i, j}});
                    visited[i][j] = true;
                }
            }
        }

        // Directions for moving to the 4 neighbors
        vector<int> dirs = {-1, 0, 1, 0, -1};
        int waterTrapped = 0;

        // Process cells in the min-heap
        while (!minHeap.empty()) {
            auto [height, cell] = minHeap.top();
            minHeap.pop();
            int x = cell.first, y = cell.second;

            for (int d = 0; d < 4; ++d) {
                int nx = x + dirs[d];
                int ny = y + dirs[d + 1];

                // Skip invalid or already visited neighbors
                if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[nx][ny]) continue;

                // Calculate trapped water
                waterTrapped += max(0, height - heightMap[nx][ny]);

                // Update neighbor height and push it into the heap
                minHeap.push({max(height, heightMap[nx][ny]), {nx, ny}});
                visited[nx][ny] = true;
            }
        }

        return waterTrapped;
    }
};