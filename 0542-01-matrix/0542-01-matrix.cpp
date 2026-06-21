class Solution {
public:
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int bfs(vector<vector<int>>& mat, queue<pair<int, int>>& zeros,
            vector<vector<int>>& result) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int levels = 1;
        while (!zeros.empty()) {
            int s = zeros.size();
            while (s--) {
                pair<int, int> temp = zeros.front();
                zeros.pop();
                for (auto d : dir) {
                    int newX = temp.first + d.first;
                    int newY = temp.second + d.second;
                    if (newX >= 0 && newX < m && newY >= 0 && newY < n &&
                        !visited[newX][newY] && mat[newX][newY] == 1) {
                        result[newX][newY] = levels;
                        visited[newX][newY] = 1;
                        zeros.push({newX, newY});
                    }
                }
            }
            levels++;
        }
        return levels;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> result(m, vector<int>(n, 0));
        queue<pair<int, int>> zeros;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    zeros.push({i, j});
                }
            }
        }
        bfs(mat, zeros, result);
        return result;
    }
};