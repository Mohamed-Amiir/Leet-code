class Solution {
    // to be rechecked
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int maxDay = days.back(); // The last day of travel
        unordered_set<int> travelDays(days.begin(), days.end());
        vector<int> dp(maxDay + 1, 0);
        
        for (int i = 1; i <= maxDay; ++i) {
            if (travelDays.count(i) == 0) {
                // If not a travel day, cost is same as the previous day
                dp[i] = dp[i - 1];
            } else {
                // Take the minimum cost of all possible ticket options
                dp[i] = min({
                    dp[i - 1] + costs[0], 
                    dp[max(0, i - 7)] + costs[1], 
                    dp[max(0, i - 30)] + costs[2]
                });
            }
        }
        
        return dp[maxDay];
    }
};
