class Solution {
public:
    bool isPrefixAndSuffix(string x,string y){
         string temp = y,t = x; 
         reverse(temp.begin(),temp.end());
         reverse(t.begin(),t.end());
         if(y.find(x) != string::npos && temp.find(t) != string::npos){
            for(int k = 0;k < x.size();k++){
                if(x[k] != y[k] || t[k] != temp[k]){
                   return 0;
                }
            }
            return 1;
         }
         return 0;
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