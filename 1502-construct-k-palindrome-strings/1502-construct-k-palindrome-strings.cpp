class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size() < k) return false;
        unordered_map<char,int> chars;
        int c = 0;
        for(auto c:s){
           chars[c]++;
        }
        for(auto x : chars){
            if(x.second % 2 != 0)c++;
        }
        return c <= k;
    }
};