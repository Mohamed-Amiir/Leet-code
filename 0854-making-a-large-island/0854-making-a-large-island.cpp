#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
    static constexpr pair<int, int> dirs[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int BFS(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& idGrid, int id) {
        int n = grid.size(), m = grid[0].size();
        if (grid[i][j] != 1 || idGrid[i][j] != 0) return 0;

        queue<pair<int, int>> q;
        q.emplace(i, j);
        idGrid[i][j] = id;
        int count = 1;

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (auto [dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1 && idGrid[nx][ny] == 0) {
                    idGrid[nx][ny] = id;
                    q.emplace(nx, ny);
                    ++count;
                }
            }
        }
        return count;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = n ? grid[0].size() : 0;
        if (n == 0) return 0;

        int maxArea = 0, id = 1;
        vector<vector<int>> idGrid(n, vector<int>(m, 0));
        vector<int> islandAreas(1, 0); // id starts at 1, index 0 unused

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1 && idGrid[i][j] == 0) {
                    if (id >= islandAreas.size()) islandAreas.resize(id + 1);
                    int area = BFS(i, j, grid, idGrid, id);
                    islandAreas[id++] = area;
                    maxArea = max(maxArea, area);
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 0) {
                    unordered_set<int> seen;
                    int curr = 1;
                    for (auto [dx, dy] : dirs) {
                        int nx = i + dx, ny = j + dy;
                        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                            int adjId = idGrid[nx][ny];
                            if (adjId != 0 && !seen.count(adjId)) {
                                curr += islandAreas[adjId];
                                seen.insert(adjId);
                            }
                        }
                    }
                    maxArea = max(maxArea, curr);
                }
            }
        }

        return maxArea != 0 ? maxArea : n * m; // Handles all 1s case
    }
};