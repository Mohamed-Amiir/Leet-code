class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int l = 0,r = 1;
        while(l < prices.size()-1){
            
            if(prices[r] <= prices[l]){
                prices[l] -= prices[r];
                l++;
                r = l+1;
            }
            else{
               r++;
               if(r == prices.size()){
                    l++;
                    r = l+1;
               }
            }
        }
        return prices;
    }
};