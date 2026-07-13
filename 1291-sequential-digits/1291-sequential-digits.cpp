class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        for (int i = 1; i < 10; i++) {
            int newInt = i, j = i+1;
            while (newInt < high && j < 10) {
                newInt = newInt * 10 + j;
                j++;
                if (newInt >= low && newInt <= high)
                    result.push_back(newInt);
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};