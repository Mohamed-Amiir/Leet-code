class Solution {
    //to be rechecked
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int MOD = 1e9 + 7;
        vector<int> dp(high + 1, 0);
        dp[0] = 1; // Base case: There's one way to construct a string of length 0.

        for (int i = 0; i <= high; ++i) {
            if (dp[i] > 0) {
                if (i + zero <= high) {
                    dp[i + zero] = (dp[i + zero] + dp[i]) % MOD;
                }
                if (i + one <= high) {
                    dp[i + one] = (dp[i + one] + dp[i]) % MOD;
                }
            }
        }

        int result = 0;
        for (int i = low; i <= high; ++i) {
            result = (result + dp[i]) % MOD;
        }

        return result;
    }
};
