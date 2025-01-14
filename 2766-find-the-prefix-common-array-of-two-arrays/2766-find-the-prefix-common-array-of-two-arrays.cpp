class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> counter(51, 0);

        vector<int> result(n);

        for (int i = 0; i < n; i++) {
            counter[A[i]]++;
            counter[B[i]]++;

            int c = 0;
            if (i > 0)
                c = result[i - 1];
            if (A[i] == B[i])
                c++;
            else {
                if (counter[A[i]] == 2)
                    c++;
                if (counter[B[i]] == 2)
                    c++;
            }
            result[i] = c;
        }
        return result;
    }
};