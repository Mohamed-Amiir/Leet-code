class Solution {
public:
    bool isPrefixAndSuffix(string x,string y){
        for(int k = 0;k < x.size();k++){
            if(x[k] != y[k]){
                return 0;
            }
        }
        int a = x.size()-1;
        for(int k = y.size()-1;a >= 0;k--){
            if(x[a] != y[k]){
                return 0;
            }
            a--;
        }
        return 1;
    } 
    int countPrefixSuffixPairs(vector<string>& words) {
        int c = 0;
        for(int i = 0;i < words.size();i++){
            for(int j = i+1;j < words.size();j++){
                if(isPrefixAndSuffix(words[i],words[j]))c++;
            }
        }
        return c;
    }
};