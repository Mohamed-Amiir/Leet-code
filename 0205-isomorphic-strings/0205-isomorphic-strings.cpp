class Solution {
public:
    bool isIsomorphic(string s, string t) {
        set<char> ss (s.begin(),s.end());
        set<char> tt (t.begin(),t.end());
        if(ss.size() != tt.size())
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