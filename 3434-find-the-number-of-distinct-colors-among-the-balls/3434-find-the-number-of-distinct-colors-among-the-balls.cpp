class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size(), c = 0;
        unordered_map<int,int> colored;
        unordered_map<int, int> used;
        vector<int> result(n);

        for (int i = 0; i < n; i++) {
            int ball = queries[i][0], color = queries[i][1], curColor = colored[ball];


            // used[curColor]--;
            if (--used[curColor] == 0)c--;

            // used[color]++;
            if (++used[color] == 1)c++;

            colored[ball] = color;

            result[i] = c;
        }
        return result;
    }
};