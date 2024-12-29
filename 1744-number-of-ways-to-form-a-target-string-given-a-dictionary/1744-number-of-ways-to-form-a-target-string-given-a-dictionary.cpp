class Solution {
    /// TO BE RECHECKED
public:
    int numWays(vector<string>& words, string target) {
    const int MOD = 1e9 + 7;
    int m = words.size(), n = words[0].size();
    int t_len = target.size();

    // Precompute the frequency of each character at each column
    vector<vector<int>> freq(n, vector<int>(26, 0));
    for (const string& word : words) {
        for (int j = 0; j < n; ++j) {
            freq[j][word[j] - 'a']++;
        }
    }

    // DP array: dp[i] is the number of ways to form the first i characters of target
    vector<long long> dp(t_len + 1, 0);
    dp[0] = 1; // Base case: 1 way to form an empty string

    // Traverse columns of words
    for (int j = 0; j < n; ++j) {
        // Update dp array from back to front
        for (int i = t_len - 1; i >= 0; --i) {
            if (target[i] - 'a' < 26) {
                dp[i + 1] += dp[i] * freq[j][target[i] - 'a'];
                dp[i + 1] %= MOD;
            }
        }
    }

    return dp[t_len];
}
};