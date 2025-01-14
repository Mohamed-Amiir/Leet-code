class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n  = A.size();
        vector<int> mapa(51,-1),mapb(51,-1);
        // unordered_map<int,int> mapa, mapb;
        vector<int> result(n);

        for(int i = 0; i < n;i++){
            mapa[A[i]] = i;
            mapb[B[i]] = i;
        }
        for(int i = n-1;i >= 0; i--){
            int c = 0;
            for(int j = 1; j <= 50; j++){
                if( (mapa[j] != -1 && mapb[j] != -1) && mapa[j] <= i && mapb[j] <= i)c++;
            }
            result[i] = c;
        }
        return result;
    }
};