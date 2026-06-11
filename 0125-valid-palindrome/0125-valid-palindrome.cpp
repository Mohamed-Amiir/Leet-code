class Solution {
public:
    bool isPalindrome(string s) {
        string s2 = ""; 
        for (int i = 0; i < s.size(); i++) {
            s[i] = tolower(s[i]);
            char c = s[i];
            if (int(c) >= int('a') && int(c) <= int('z') || (isdigit(c)))
                s2.push_back(c);
        }
        // cout << "AFTER PROCESSING: " << s2 << endl;
        int l = 0, r = s2.size() - 1;
        while (l <= r) {
            if (s2[l] != s2[r])
                return 0;
            l++;
            r--;
        }
        return true;
    }
};