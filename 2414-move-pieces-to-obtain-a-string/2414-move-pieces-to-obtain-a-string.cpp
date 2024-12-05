class Solution {
public:
    bool canChange(string start, string target) {
        int j = 0; // Pointer for the start string

        for (int i = 0; i < target.size(); i++) {
            if (target[i] == 'L') {
                // Find the next 'L' in start
                while (j < start.size() && start[j] != 'L') {
                    if (start[j] == 'R') return false; // 'R' blocks 'L'
                    j++;
                }
                if (j >= start.size() || j < i) return false; // 'L' cannot move right or is not found
                j++; // Move to the next position
            } else if (target[i] == 'R') {
                // Find the next 'R' in start
                while (j < start.size() && start[j] != 'R') {
                    if (start[j] == 'L') return false; // 'L' blocks 'R'
                    j++;
                }
                if (j >= start.size() || j > i) return false; // 'R' cannot move left or is not found
                j++; // Move to the next position
            }
        }

        // After processing target, ensure all remaining characters in start are blanks
        while (j < start.size()) {
            if (start[j] != '_') return false;
            j++;
        }

        return true;
    }
};
