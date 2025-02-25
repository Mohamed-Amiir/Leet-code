class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(magazine.size() < ransomNote.size())return 0;
        unordered_map<char,int> mCount;
        for(char c : magazine){
            mCount[c]++;
        }
        for(char c : ransomNote){
            if(mCount[c] == 0)
               return 0;
            mCount[c]--;
        }
        return 1;
    }
};