class Solution {
public:
    bool check(int a, int b, int c, int d) { return a >= c && b <= d; }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int result = n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && check(intervals[i][0], intervals[i][1],
                                    intervals[j][0], intervals[j][1]))
                    {
                        result--;
                        break;
                    }

            }
        }
        return result;
    }
};