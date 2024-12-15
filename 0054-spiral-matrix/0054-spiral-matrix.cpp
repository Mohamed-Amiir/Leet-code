class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int c = 0;
        int i = 0, j = 0, columns = matrix[0].size(), rows = matrix.size();
        bool r = true, l = false, u = false, d = false;
        vector<vector<bool>> visited(rows, vector<bool>(columns, false));

        while (c < (columns * rows)) {
            int temp1 = i, temp2 = j;
            result.push_back(matrix[i][j]);
            visited[i][j] = true;
            c++;

            if (r) {
                temp2++;
            } else if (l) {
                temp2--;
            } else if (u) {
                temp1--;
            } else if (d) {
                temp1++;
            }

            if (temp1 < rows && temp2 < columns && temp1 >= 0 && temp2 >= 0 && !visited[temp1][temp2]) {
                i = temp1;
                j = temp2;
            } else {
                // Change direction
                if (r) {
                    d = true;
                    r = false;
                } else if (l) {
                    u = true;
                    l = false;
                } else if (u) {
                    r = true;
                    u = false;
                } else if (d) {
                    l = true;
                    d = false;
                }

                if (r) {
                    j++;
                } else if (l) {
                    j--;
                } else if (u) {
                    i--;
                } else if (d) {
                    i++;
                }
            }
        }
        return result;
    }
};
