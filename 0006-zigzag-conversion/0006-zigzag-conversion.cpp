class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1||s.size()==1)return s;
        int numCols = s.size();
        vector<vector<char>> matrix(numRows, vector<char>(numCols));
        int r = 0, c = 0;
        bool flag = true;
        for (char a : s) {

            matrix[r][c] = a;

            if (flag)
                r++;
            else {
                r--;
                c++;
            }

            if (r == numRows - 1) {
                flag = false;
            }
            if (r == 0) {
                flag = true;
            }
        }
        string result = "";
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                if (matrix[i][j] != '\0')
                    result += matrix[i][j];
            }
        }
        return result;
    }
};