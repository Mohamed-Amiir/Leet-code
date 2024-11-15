class Solution {
public:
    bool isValid(char& x,map<char,int>& s,map<char,int>& t){
       return s[x] > t[x];
    }
    bool isValidSub(map<char,int>& s,map<char,int>& t){
          for(auto x : t){
            if(s[x.first] < x.second)
              return false;
          }
          return 1;
    }
    string minWindow(string s, string t) {
        int l = 0 , r = 0;
        map<char,int> tt;
        for(char x : t)
           tt[x]++;

        map<char,int> ss;
        string result ;
        int mini = 1e9;
        while(r < s.size()){
            r = max(r,l);
            ss[s[r]]++;
            for(;l <= r;l++){

                if(isValid(s[l],ss,tt))
                    ss[s[l]]--;
                else
                  break;
            }
            if(r-l+1 < mini && isValidSub(ss,tt)){
               result = s.substr(l,r-l+1);
               mini = r - l+1;
            }
            r++;
        }

        return result;

    }
};