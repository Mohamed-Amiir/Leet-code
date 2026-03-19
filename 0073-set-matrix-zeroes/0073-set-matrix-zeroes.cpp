class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        set<int> r, c;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    r.insert(i);
                    c.insert(j);
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    r.insert(i);
                    c.insert(j);
                }
            }
        }

        for (int x : r) {
            vector<int> temp(n, 0);
            matrix[x] = temp;
        }
        for (int x : c) {
            for (int j = 0; j < m; j++) {
                matrix[j][x] = 0;
            }
        }

    }
};