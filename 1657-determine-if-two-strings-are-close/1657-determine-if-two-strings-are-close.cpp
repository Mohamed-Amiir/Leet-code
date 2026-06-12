class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size())return false;
        set<char> s1(word1.begin(),word1.end());
        set<char> s2(word2.begin(),word2.end());
        if(s1 != s2) return false;
        unordered_map<char,int>freq1,freq2;
        for(int i  =0 ;i < word1.size();i++){
            freq1[word1[i]]++;
            freq2[word2[i]]++;
        }
        string pattern1 = "", pattern2 = "";
        for(auto p : freq1){
            pattern1 += ('0'+p.second);
        }
        for(auto p : freq2){
            pattern2 += ('0'+p.second);
        }
        sort(pattern1.begin(),pattern1.end());
        sort(pattern2.begin(),pattern2.end());
        return pattern1 == pattern2;
    }
};