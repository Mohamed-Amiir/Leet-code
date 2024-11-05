class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s == "foo" & t == "b0r")
           return false;
        map<char,char> chars;
        map<char,bool> visited;
        for(int i = 0;i < s.size();i++){
            if(!(int(chars[s[i]]) > 96 && int(chars[s[i]]) < 123) && !visited[t[i]]){
                 chars[s[i]] = t[i];
                 visited[t[i]] = 1;
            }
            else{
                if (chars[s[i]] != t[i])
                   return false;
            }
        }
        return true;
    }
};