class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size())
            return false;
        // set<char> s1(word1.begin(), word1.end());
        // set<char> s2(word2.begin(), word2.end());
        // if (s1 != s2)
        //     return false;
        // unordered_map<char, int> freq1, freq2;
        vector<int> freq1(26),freq2(26);
        for (int i = 0; i < word1.size(); i++) {
            freq1[word1[i] - 'a']++;
            freq2[word2[i] - 'a']++;
        }
        for(int i = 0 ;i < 26 ;i++){
            if((freq1[i] == 0) != (freq2[i] == 0))
                return false;
        }
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());
        return freq1 == freq2;
    }
};