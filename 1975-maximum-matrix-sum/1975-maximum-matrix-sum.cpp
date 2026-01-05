class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long result = 0;
        int c = 0, n = matrix.size(), mini = 1e5 + 2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] < 0) {
                    c++;
                    matrix[i][j] *= -1;
                }
                result += matrix[i][j];
                mini = min(mini, matrix[i][j]);
            }
        }
        cout << result << "  " << c << "  " << mini ;
        if (c % 2 == 0)
            return result;
        else
            return ( result - mini ) - mini;
    }
};