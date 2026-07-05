class Solution {
public:
    bool check(int x, int y, int n) {
        return x >= 0 && x < n && y >= 0 && y < n;
    }
    void display(vector<vector<int>> mat) {
        for (auto v : mat) {
            for (auto x : v) {
                cout << x << " ";
            }
            cout << endl;
        }
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        const int MOD = 1e9 + 7;
        int n = board.size();

        vector<vector<int>> score(n, vector<int>(n, -1));
        vector<vector<int>> ways(n, vector<int>(n, 0));

        vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {1, 1}};

        board[0][0] = '0';
        board[n - 1][n - 1] = '0';
        ways[n - 1][n - 1] = 1;
        score[n - 1][n - 1] = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (board[i][j] == 'X' || (i == n - 1 && j == n - 1))
                    continue;
                int candidate = 0;
                for (auto d : dirs) {
                    int nx = i + d.first;
                    int ny = j + d.second;
                    if (check(nx, ny, n) && board[nx][ny] != 'X' &&
                        ways[nx][ny] != 0) {
                        candidate = score[nx][ny] + (board[i][j] - '0');
                        if (candidate > score[i][j]) {
                            score[i][j] = candidate;
                            ways[i][j] = ways[nx][ny];
                        } else if (candidate == score[i][j]) {
                            ways[i][j] = (ways[i][j] + ways[nx][ny]) % MOD;
                        }
                    }
                }
            }
        }
        // display(score);
        // display(ways);
        if (ways[0][0] == 0)
            return {0, 0};
        return {score[0][0], ways[0][0]};
    }
};