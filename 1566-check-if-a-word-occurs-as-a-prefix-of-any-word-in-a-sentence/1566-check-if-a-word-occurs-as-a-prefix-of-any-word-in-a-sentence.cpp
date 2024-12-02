class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int c = 1;                      // Word counter (1-indexed)
        int j = 0;                      // Pointer for searchWord
        int correct = searchWord.size(); // Characters left to match

        for (int i = 0; i < sentence.size(); i++) {
            if (sentence[i] == ' ') {
                // Word boundary reached
                c++;                     // Move to the next word
                correct = searchWord.size(); // Reset correct to searchWord size
                j = 0;                   // Reset pointer for searchWord
                continue;
            }

            if (sentence[i] == searchWord[j]) {
                j++;
                correct--;
            }
            else {
                // Reset progress for this word if a mismatch occurs
                if (j > 0) {
                    j = 0;
                    correct = searchWord.size();
                }
            }

            if (correct == 0) {
                // Check if the prefix is matched completely at the start of a word
                if (i - j + 1 == 0 || sentence[i - j] == ' ') {
                    return c;
                }
                // Otherwise reset to check for further valid matches
                j = 0;
                correct = searchWord.size();
            }
        }

        return -1; // No match found
    }
};
