class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int result = 0, m = grid.size(), n = grid[0].size();
        vector<int> rows(m),columns(n);
        for(int i = 0; i < m ;i++){
            for(int j = 0; j < n ; j++){
               if(grid[i][j] == 1){
                rows[i]++;
                columns[j]++;
               }
            }
        }
        for(int i = 0; i < m ;i++){
            for(int j = 0; j < n ; j++){
               if(grid[i][j] == 1){
                if(rows[i] > 1 || columns[j] > 1)result++;
               }
            }
        }
        return result;
    }
};