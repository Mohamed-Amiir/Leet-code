class Solution {
public:
//to be rechecked
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if (n % 2 != 0) return false; // Odd length cannot be valid
        
        // Forward pass
        int balance = 0;
        for (int i = 0; i < n; ++i) {
            if (locked[i] == '0' || s[i] == '(') {
                balance++;
            } else {
                balance--;
            }
            if (balance < 0) return false; // More ')' than '(' + wildcards
        }
        
        // Backward pass
        balance = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (locked[i] == '0' || s[i] == ')') {
                balance++;
            } else {
                balance--;
            }
            if (balance < 0) return false; // More '(' than ')' + wildcards
        }
        
        return true; // Both passes succeeded
    }
};
