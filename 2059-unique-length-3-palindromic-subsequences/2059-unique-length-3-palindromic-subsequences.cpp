class Solution {
public:
//TBR
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int> firstPos(26, -1), lastPos(26, -1);
        int result = 0;

        // Record the first and last positions of each character
        for (int i = 0; i < n; ++i) {
            int idx = s[i] - 'a';
            if (firstPos[idx] == -1) {
                firstPos[idx] = i;
            }
            lastPos[idx] = i;
        }

        // Count unique palindromes
        for (int c = 0; c < 26; ++c) {
            if (firstPos[c] != -1 && lastPos[c] != -1 && firstPos[c] < lastPos[c]) {
                unordered_set<char> middleChars;
                for (int i = firstPos[c] + 1; i < lastPos[c]; ++i) {
                    middleChars.insert(s[i]);
                }
                result += middleChars.size();
            }
        }

        return result;
    }
};
