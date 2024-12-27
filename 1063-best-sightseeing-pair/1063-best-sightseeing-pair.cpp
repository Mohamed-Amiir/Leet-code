class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {

        priority_queue<pair<int, int>> pq_j;
        int n = values.size();
        int res = 0, curI = values[0];
        for (int i = 1; i < n; i++) {
            res = max(res, curI + (values[i] - i));
            curI = max(curI, values[i] + i);
            // pq_j.push({values[i] - i, i});
        }

        return res;
    }
};