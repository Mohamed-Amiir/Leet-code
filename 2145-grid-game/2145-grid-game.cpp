class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        
        // Calculate prefix sums for both rows
        vector<long long> prefix1(n + 1, 0), prefix2(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefix1[i] = prefix1[i - 1] + grid[0][i - 1];
            prefix2[i] = prefix2[i - 1] + grid[1][i - 1];
        }
        
        // Find the optimal column for the first robot to switch rows
        long long result = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            // First robot goes right on row 0 until column i, then switches to row 1
            long long option1 = prefix1[n] - prefix1[i + 1]; // Remaining in row 0
            long long option2 = prefix2[i]; // Remaining in row 1
            long long secondRobotScore = max(option1, option2);
            result = min(result, secondRobotScore);
        }
        
        return result;
    }
};