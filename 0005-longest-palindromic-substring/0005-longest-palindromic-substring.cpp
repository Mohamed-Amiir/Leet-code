class Solution {
public:
    bool is_pal(string s) {
        int l = 0, r = s.size() - 1;
        int n = s.size();
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        string result = "";
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j >= i; j--) {
                if (s[i] == s[j]) {
                    string temp = s.substr(i, j - i + 1);
                    // cout << "TEMP : " << temp << endl;
                    if (result.size() < temp.size()) {

                        if (is_pal(temp)) {
                            // cout << "IS PAL" << endl;
                            result = temp;
                        }
                    }
                }
            }
        }
        return result;
    }
};