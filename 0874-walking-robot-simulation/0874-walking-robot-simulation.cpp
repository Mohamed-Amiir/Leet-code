class Solution {
public:
    long long convert(int x, int y) { return (long long)x * 60001 + y; }
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<long long> isObs;
        for (auto o : obstacles) {
            isObs.insert(convert(o[0], o[1]));
        }
        int x = 0, y = 0, result = 0;
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int d = 0;
        for (int c : commands) {
            if (c == -1) {
                d++;
                if (d == 4)
                    d = 0;
            } else if (c == -2) {
                d--;
                if (d == -1)
                    d = 3;
            } else {
                while (c--) {
                    int nx = dirs[d].first, ny = dirs[d].second;
                    if (isObs.count(convert(x + nx, y + ny)))
                        break;
                    x += nx;
                    y += ny;
                }
                result = max(result, (x * x) + (y * y));
            }
        }
        // int result = pow(x, 2) + pow(y, 2);
        return result;
    }
};