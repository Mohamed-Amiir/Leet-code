class Solution {
public:
bool isPalindrome(string s) {
    // lets go
    int i = 0, j = s.size() - 1;
    while (i < j) {

        if (!isalnum(s[i])) {
            i++;
            continue;
        }
        else
            s[i] = tolower(s[i]);
        if (!isalnum(s[j])) {
            j--;
            continue;
        }
        else
            s[j] = tolower(s[j]);

        if (s[i] != s[j])
            return false;
        j--;
        i++;
    }
    return true;
}
};