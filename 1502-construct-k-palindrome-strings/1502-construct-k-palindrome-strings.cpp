class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size() < k) return false;
        int chars[26] = {};
        int c = 0;
        for(auto x : s){
           chars[x-'a']++;
        }
        for(auto x : chars){
            if(x % 2 != 0)c++;
        }
        return c <= k;
    }
};