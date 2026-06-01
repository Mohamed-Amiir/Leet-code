class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int result = 0;
        sort(cost.begin(),cost.end(),greater<int>());
        bool x = 0 ,y =0 ;
        for(int c : cost){
            if(x && y){
                x = 0;y =0;
                continue;
            }
            if(!x && !y){
                result += c;
                x = true;
            }
            else if(x && !y){
                result += c;
                y = true;
            }
        }
        return result;
    }
};