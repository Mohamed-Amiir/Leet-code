class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int curAlt = 0,result = 0;
        for(int x : gain){
            curAlt += x;
            result = max(result, curAlt);
        }
        return result ;
    }
};