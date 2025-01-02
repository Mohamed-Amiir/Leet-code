class Solution {
public:
    int maxScore(string s) {
        vector<int> zeros, ones(s.size());
        int z = 0, o = 0;
        for (auto c : s) {
            if (c == '0') {
                z++;
            }
            zeros.push_back(z);
            // ones.push_back(o);
        }
        for(int i = s.size()-1;i >= 0 ; i--){
            if(s[i]== '1'){
                o++;
            }
            ones[i] = o;
        }
        // reverse(ones.begin(),ones.end());
        int result = 0;
        for(int i = 1;i < s.size();i++){
           result = max(result,zeros[i-1]+ones[i]);
        }
        return result;
    }
};