class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int result = 0;
        vector<int> counts(1e5 + 1, 0), sortedCosts;
        for (int x : costs) {
            counts[x]++;
        }
        for (int i = 1; i < counts.size(); i++) {
                int canBuy = coins / i;
                if(canBuy >= counts[i]){
                    result += counts[i];
                    coins -= counts[i]*i;
                }else{
                    result += canBuy;
                    return result ;
                }

        }
        // for (int c : sortedCosts) {
        //     if (coins >= c) {
        //         result++;
        //         coins -= c;
        //     }
        // }
        return result;
    }
};