class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        unordered_map<char,int>c1,c2;
        for(auto c : s1){
            c1[c]++;
        }
        for(auto c : s2){
            c2[c]++;
        }
        for(auto x : c1){
            if(c2[x.first] != x.second)return false;
        }
        int wrong = 0;
        for(int i = 0;i < s1.size();i++){
            if(wrong > 2)return false;
            if(s1[i] != s2[i])wrong++;
        } 
        return wrong <= 2;
    }
};