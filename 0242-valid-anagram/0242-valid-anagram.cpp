class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return 0;
        int a = 0 ,b = 0;
        vector<int> freq1(26),freq2(26);
        for(int i= 0 ; i < s.size();i++){
            freq1[s[i]-'a']++;
            freq2[t[i]-'a']++;
        }
        for(int i= 0 ; i < 26;i++){
           if (freq1[i] != freq2[i])return 0;
        }
        return 1;
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // return s ==t;
    }
};