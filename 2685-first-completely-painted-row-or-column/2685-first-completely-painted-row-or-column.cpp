class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(),n = mat[0].size(),a = arr.size();
        unordered_map<int, int> ind;
        for (int i = 0; i < a ;i++) {
            ind[arr[i]] = i;
        }
        int result = 1e9;
        for (int i = 0; i < m; i++) {
            int res = -1;
            for (int j = 0; j < n; j++) {
                int x = mat[i][j];
                res = max(res,ind[x]);
            }
            result = min(res,result);
        }
        for (int i = 0; i < n; i++) {
            int res = -1;
            for (int j = 0; j < m; j++) {
                int x = mat[j][i];
                res = max(res,ind[x]);
            }
            result= min(res,result);
        }
        return result;
    }
};