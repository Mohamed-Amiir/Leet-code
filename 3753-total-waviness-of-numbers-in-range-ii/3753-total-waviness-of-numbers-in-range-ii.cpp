class Solution {
public:
    struct Node {
        long long cnt;   // number of valid numbers
        long long sum;   // total waviness
    };

    string s;
    Node memo[20][2][3][11][11];
    bool vis[20][2][3][11][11];

    Node dfs(int pos, bool tight, bool started,
             int prev2, int prev1, int state) {
        if (pos == (int)s.size()) {
            return {1, 0};
        }

        if (!tight && vis[pos][started][state][prev2][prev1]) {
            return memo[pos][started][state][prev2][prev1];
        }

        int limit = tight ? (s[pos] - '0') : 9;

        long long totalCnt = 0;
        long long totalSum = 0;

        for (int d = 0; d <= limit; d++) {
            bool ntight = tight && (d == limit);

            if (!started && d == 0) {
                Node nxt = dfs(pos + 1, ntight, false, 10, 10, 0);
                totalCnt += nxt.cnt;
                totalSum += nxt.sum;
                continue;
            }

            if (!started) {
                Node nxt = dfs(pos + 1, ntight, true, 10, d, 1);
                totalCnt += nxt.cnt;
                totalSum += nxt.sum;
            } else if (state == 1) {
                Node nxt = dfs(pos + 1, ntight, true, prev1, d, 2);
                totalCnt += nxt.cnt;
                totalSum += nxt.sum;
            } else { // state == 2 (already have at least 2 digits)
                long long add = 0;

                if ((prev1 > prev2 && prev1 > d) ||
                    (prev1 < prev2 && prev1 < d)) {
                    add = 1;
                }

                Node nxt = dfs(pos + 1, ntight, true, prev1, d, 2);

                totalCnt += nxt.cnt;
                totalSum += nxt.sum + add * nxt.cnt;
            }
        }

        Node res{totalCnt, totalSum};

        if (!tight) {
            vis[pos][started][state][prev2][prev1] = true;
            memo[pos][started][state][prev2][prev1] = res;
        }

        return res;
    }

    long long solve(long long n) {
        if (n < 0) return 0;

        s = to_string(n);
        memset(vis, 0, sizeof(vis));

        return dfs(0, true, false, 10, 10, 0).sum;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};