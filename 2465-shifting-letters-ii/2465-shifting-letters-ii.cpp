class Solution {
public:
// 
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> shiftAmount(n + 1, 0); // Initialize shift array with an extra element
        
        // Populate the shift array
        for (const auto& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];
            
            shiftAmount[start] += (direction == 1 ? 1 : -1); // Add shift value at start
            shiftAmount[end + 1] -= (direction == 1 ? 1 : -1); // Subtract shift value after end
        }
        
        // Calculate the cumulative shifts using prefix sum
        int netShift = 0;
        for (int i = 0; i < n; ++i) {
            netShift += shiftAmount[i];
            int effectiveShift = (netShift % 26 + 26) % 26; // Normalize shift to [0, 25]
            s[i] = 'a' + (s[i] - 'a' + effectiveShift) % 26; // Apply the shift
        }
        
        return s;
    }
};
