class Solution {
public:
   int maxProfit(vector<int>&prices) {
    int n = prices.size();
	int a = INT_MAX, x = 0;

    for(int i =0 ;i < n;i++){
      a = min (a,prices[i]);
      x = max (x,prices[i] - a);
    }
    return x;
   }
};