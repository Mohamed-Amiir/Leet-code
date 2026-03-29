class Solution {
public:
    unordered_map<int, int> dp;

    int climbStairs(int n) {
        if (n == 0 || n == 1)
            return 1;
        if (dp.find(n) != dp.end())
            return dp[n];
        return dp[n] = climbStairs(n-1)+climbStairs(n-2);
    }
};