class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int j = 0;
        int counter = -1;
        string result;

        for (int i = 0; i < s.size(); i++) {
            counter++;

            // Before adding character, check if a space should be inserted
            if (j < spaces.size() && spaces[j] == counter) {
                result.push_back(' '); // Add the space
                j++;  // Move to the next space index
            }

            // Add the current character
            result.push_back(s[i]);
        }

        return result; // Return the modified string
    }
};
