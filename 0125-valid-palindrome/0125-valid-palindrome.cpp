class Solution {
public:
bool isPalindrome(string s) {
    for (int i = 0; i < s.size(); i++) {
        s[i] = tolower(s[i]);
        if (!isalnum(s[i])) {
            s.erase(s.begin() + i);
            i--; // Adjust index after erasing a character
        }
    }
    // lets go
    int i = 0, j = s.size()-1;
    while (j != -1) {
        if (s[i] == ' ')
            i++;
        if (s[j] == ' ')
            j--;

        if (s[i] != s[j])
            return false;
        j--;
        i++;
    }
    return true;
}
};