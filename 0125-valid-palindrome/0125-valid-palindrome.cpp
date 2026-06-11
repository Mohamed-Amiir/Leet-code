class Solution {
public:
    bool isPalindrome(string s) {
        // string s2 = ""; 
        // for (int i = 0; i < s.size(); i++) {
        //     s[i] = tolower(s[i]);
        //     char c = s[i];
        //     if (int(c) >= int('a') && int(c) <= int('z') || (isdigit(c)))
        //         s2.push_back(c);
        // }
        int l = 0, r = s.size() - 1;
        while (l <= r) {

            while(l < r && !isalnum(s[l])){
                l++;
            }
            while(l < r && !isalnum(s[r])){
                r--;
            }
            
        
            if (tolower(s[l]) != tolower(s[r]))
                return 0;
            l++;
            r--;
        }
        return true;
    }
};