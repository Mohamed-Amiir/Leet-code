class Solution {
public:

    int maximumLength(string s) {
        int n = s.length();
        unordered_map<string, int> substrCount;

        // Generate all substrings made up of a single character
        for (int i = 0; i < n; ++i) {
            char ch = s[i];
            // Generate substrings starting from index i
            string currentSubstring;
            for (int j = i; j < n; ++j) {
                if (s[j] == ch) {
                    currentSubstring += s[j];
                    substrCount[currentSubstring]++;
                } else {
                    break;
                }
            }
        }

        // Now find the longest special substring that appears at least 3 times
        int maxLength = -1;
        for (const auto& entry : substrCount) {
            if (entry.second >= 3) {
                maxLength = max(maxLength, (int)entry.first.length());
            }
        }

        return maxLength;
    }

};