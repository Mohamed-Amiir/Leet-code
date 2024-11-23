class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int arrows = 0;
        long long end = LONG_MIN; 
        for (const auto& balloon : points) {
            if (balloon[0] > end) {
                arrows++;              
                end = balloon[1];       
            }
        }

        return arrows;
    }
};
