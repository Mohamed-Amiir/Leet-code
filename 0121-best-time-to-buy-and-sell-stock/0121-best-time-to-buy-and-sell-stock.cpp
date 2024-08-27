class Solution {
public:
   int maxProfit(vector<int>&prices) {
	map<int, int> dp;
	int res = 0;
	int bestStart = -1;
	for (int i = 0; i < prices.size() - 1; i++)
	{
		if (dp[prices[i]] != 0 || prices[i+1] < prices[i])
		{
			continue;
		}
		if ((prices[i] > bestStart && bestStart != -1))
		{
			continue;
		}
		for (int j = i + 1; j < prices.size(); j++)
		{
			if (prices[j] - prices[i] > res)
			{
				res = prices[j] - prices[i];
				bestStart = prices[i];
				dp[prices[i]] = res;
			}
			
		}
		if (dp[prices[i]] == 0)
		{
			dp[prices[i]] = -1;
		}
	}
	return res;
}




};