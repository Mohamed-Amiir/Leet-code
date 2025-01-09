class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int c = words.size(), n = words.size();
        int k = 0;
        for(int i = 0; i < n; i++){
            k = 0;
            for(int j = 0;j < pref.size();j++){
                if(pref[k] != words[i][j]){
                    c--;
                    break;
                }
                k++;
            }
        }
        return c;
    }
};