class Solution {
public:
pair<int, int> getIndices(int x, int n) {
    x--;
    int row = n - 1 - (x / n);
    int col = x % n;

    if ((n - 1 - row) % 2 == 1) {
        col = n - 1 - col;
    }

    return {row, col};
}

int snakesAndLadders(vector<vector<int>>& board) {
    int n = board.size();
    vector<bool> visited(n*n + 1, false);

    queue<pair<int,int>> q;
    q.push({1, 0});
    visited[1] = true;

    while (!q.empty()) {
        auto [curr, moves] = q.front();
        q.pop();

        if (curr == n*n) return moves;

        for (int i = 1; i <= 6; i++) {
            int next = curr + i;
            if (next > n*n) break;

            auto [r, c] = getIndices(next, n);

            if (board[r][c] != -1) {
                next = board[r][c];
            }

            if (!visited[next]) {
                visited[next] = true;
                q.push({next, moves + 1});
            }
        }
    }

    return -1;
}
};