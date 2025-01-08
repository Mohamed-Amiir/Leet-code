class Solution {
public:
    bool isPrefixAndSuffix(string& x,string& y){
        int n = y.size(),m = x.size();
        //check prefix
        for(int k = 0;k < m;k++){
            if(x[k] != y[k]){
                return 0;
            }
        }
        //check suffix
        // int a = x.size()-1;
        m--;
        for(int k = n-1;m >= 0;k--){
            if(x[m] != y[k]){
                return 0;
            }
            m--;
        }
        return 1;
    } 
    int countPrefixSuffixPairs(vector<string>& words) {
        int c = 0,s = words.size();
        for(int i = 0;i < s;i++){
            for(int j = i+1;j < s;j++){
                if(isPrefixAndSuffix(words[i],words[j]))c++;
            }
        }
        return c;
    }
};