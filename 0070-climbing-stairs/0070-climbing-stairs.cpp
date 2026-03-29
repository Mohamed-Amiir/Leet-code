class Solution {
public:
    unordered_map<int, int> dp;

    int climbStairs(int n) {
        if (n == 0 || n == 1)
            return 1;
        int x = 0, y = 0;
        if (dp[n - 1] == 0)
            x = climbStairs(n - 1);
        else x = dp[n - 1];
        if (dp[n - 2] == 0)
            y = climbStairs(n - 2);
        else y = dp[n - 2];
        dp[n] = x+y;
        return x + y;
    }
};