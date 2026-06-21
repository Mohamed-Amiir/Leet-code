class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int result = 0;
        // sort(costs.begin(),costs.end());
        // for(int c : costs){
        //     if(coins >= c){
        //         result ++;
        //         coins-=c;
        //     }
        // }
        vector<int> counts(1e5+1, 0), sortedCosts;
        for (int x : costs) {
            counts[x]++;
        }
        for (int i = 0; i < counts.size(); i++) {
            while (counts[i]--) {
                sortedCosts.push_back(i);
            }
        }
        for (int c : sortedCosts) {
            if (coins >= c) {
                result++;
                coins -= c;
            }
        }
        return result;
    }
};