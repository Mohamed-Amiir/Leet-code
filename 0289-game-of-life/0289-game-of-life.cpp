class Solution {
public:
    vector<pair<int, int>> neighbors = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                        {0, 1},   {1, -1}, {1, 0},  {1, 1}};

    bool check(int i, int j, int m, int n) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }
    int solve(int live, int i, int j, int m, int n, vector<vector<int>> input) {
        int l = 0, d = 0;
        for (auto a : neighbors) {
            int x = a.first, y = a.second;
            int nx = i + x, ny = j + y;
            if (check(nx, ny, m, n)) {
                input[nx][ny] == 1 ? l++ : d++;
            }
        }


        if ((live == 1 && (l == 2 || l == 3)) || (live == 0 && l == 3))
            return 1;

        return 0;
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> result;
        int m = board.size(), n = board[0].size();
        result = board;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result[i][j] = solve(board[i][j], i, j, m, n, board);
            }
        }
        board = result;
    }
};