class Solution {
public:

    bool isIsomorphic(string s, string t) {
        unordered_map <char,char> chars;
        unordered_map <char,bool> visited,sign;
        for(int i = 0;i < s.size();i++){
           if(sign[s[i]] == 0 && !visited[t[i]]){
            chars[s[i]] = t[i];
            visited[t[i]] = 1;
            sign[s[i]] = 1;
           }     
           else if(chars[s[i]] != t[i])
             return false;
        }
        return true;
    }
};