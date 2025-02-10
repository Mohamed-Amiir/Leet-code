// class Solution {
// public:
//     string clearDigits(string s) {
//         unordered_map<int, char> leftChar;
//         unordered_map<int, int> deleted;
//         stack<char> chrs;
//         for (char c : s) {
//             if (int(c) >= 97 && int(c) <= 122)
//                 chrs.push(c);
//             else {
//                 if (chrs.empty())
//                     continue;
//                 deleted[int(chrs.top())]++;
//                 deleted[int(c)]++;
//                 chrs.pop();
//             }
//         }
//         string result = "";
//         for (char c : s) {
//             if (deleted[int(c)] > 0) {
//                 deleted[int(c)]--;
//             } else
//                 result.push_back(c);
//         }
//         return result;
//     }
// };


class Solution {
public:
    string clearDigits(string s) {
        stack<int> nonDigitIndices; // Stack to store indices of non-digit characters
        vector<bool> deleted(s.size(), false); // Tracks whether each index is deleted
        
        for (int i = 0; i < s.size(); ++i) {
            if (isdigit(s[i])) {
                if (!nonDigitIndices.empty()) {
                    int leftIndex = nonDigitIndices.top();
                    nonDigitIndices.pop();
                    deleted[leftIndex] = true; // Mark the non-digit character for deletion
                    deleted[i] = true; // Mark the current digit for deletion
                }
            } else {
                nonDigitIndices.push(i); // Push index of non-digit character
            }
        }
        
        string result;
        for (int i = 0; i < s.size(); ++i) {
            if (!deleted[i]) {
                result.push_back(s[i]);
            }
        }
        
        return result;
    }
};