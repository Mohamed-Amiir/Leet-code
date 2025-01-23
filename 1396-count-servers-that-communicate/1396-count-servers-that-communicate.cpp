class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int result = 0, m = grid.size(), n = grid[0].size();
        unordered_map<int,int> rows,columns;
        // unordered_map<int,vector<int>> rowsOfColumns;
        for(int i = 0; i < m ;i++){
            for(int j = 0; j < n ; j++){
               if(grid[i][j] == 1){
                rows[i]++;
                columns[j]++;
            //     if(rows[i] > 1)
            //        rowsOfColumns[j].push_back(i);
               }
            }
        }

        // for(auto r : rows){
        //     if(r.second > 1)
        //        result += r.second;
        // }
        // for(auto c : columns){
        //     if(c.second > 1)
        //        result += c.second;
        // }
        // for(auto c : columns){
        //     for(int rc : rowsOfColumns[c.first]){
        //         if(rows[rc] > 1)result--;
        //         else if(c.second > 1) result++;
        //     }
        // }
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