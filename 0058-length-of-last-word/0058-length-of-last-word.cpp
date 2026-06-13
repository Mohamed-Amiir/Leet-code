class Solution {
public:
    int lengthOfLastWord(string s) {
        // stringstream ss(s);
        // string word;
        // while(ss>>word){

        // }
        // return word.size();

        int r = s.size()-1,c = 0;
        while(s[r] == ' ')r--;
        while(r >= 0 && s[r] != ' '){
           c++;
           r--;
        }
        return c;
    }
};