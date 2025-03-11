// class Solution {
// public:
//     bool check(unordered_map<char, int>& charCount) {
//         vector<char> chars = {'a', 'b', 'c'};
//         for (char c : chars) {
//             if (charCount[c] == 0)
//                 return 0;
//         }
//         return 1;
//     }
//     int numberOfSubstrings(string s) {
//         unordered_map<char, int> charCount;
//         int l = 0, r = 0, n = s.size(), result = 0;
//         for (int i = 0; i < n; i++) {
//             l = i;
//             r = l;
//             while (!check(charCount)) {
//                 charCount[s[r]]++;
//                 r++;
//                 if(r==n)break;
//             }
//             if(check(charCount))
//                result += (n - r) + 1;
//             charCount.clear();
//         }
//         return result;
//     }
// };
class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> charCount;
        int left = 0, right = 0, n = s.size(), result = 0;
        while (right < n) {
            charCount[s[right]]++;  // Add current character to the count
            // Check if all three characters are present in the current window
            while (charCount['a'] > 0 && charCount['b'] > 0 && charCount['c'] > 0) {
                result += n - right;  // All substrings starting at left and ending at right, right+1, ..., n-1 are valid
                charCount[s[left]]--;  // Move left pointer to the right
                left++;
            }
            right++;  // Expand the window by moving right pointer
        }
        return result;
    }
};