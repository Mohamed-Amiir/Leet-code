class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size() * grid.size(),s = grid.size();
        int a ,b;
        unordered_set<int> nums;
        for(int i = 0;i < s;i ++){
            for(int j = 0; j < s;j++){
               if(count(nums.begin(),nums.end(),grid[i][j]) == 1) b = grid[i][j];
               nums.insert(grid[i][j]);
            }
        }
        for(int i = 1;i <= n;i++){
            if(count(nums.begin(),nums.end(),i) == 0){
                a = i; 
                break;
            } 
        }
        return {b,a};
    }
};