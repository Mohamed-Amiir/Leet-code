class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<unordered_map<int,int>>> cubes (3, vector<unordered_map<int,int>>(3));
        for(int i = 0;i < 9; i++){
            unordered_map<int,int>colCounter,rowCounter;
            for(int j = 0; j < 9;j++){
                if(rowCounter[board[i][j]] == 1 || colCounter[board[j][i]] == 1 ||cubes[i/3][j/3][board[i][j]] == 1)
                    return false;
                else{
                    if(board[i][j] != '.') {rowCounter[board[i][j]]++;cubes[i/3][j/3][board[i][j]]++;}
                    if(board[j][i] != '.') colCounter[board[j][i]]++;
               }
            }
        }
        return true;
    }
};