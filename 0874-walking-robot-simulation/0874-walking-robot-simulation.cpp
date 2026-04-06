class Solution {
public:
string convert(int x, int y) {
    return to_string(x) + "," + to_string(y);
}
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<string, bool> isObs;
        for (auto o : obstacles) {
            isObs[convert(o[0], o[1])] = 1;
        }
        int x = 0, y = 0, result = 0;
        vector<char> dirs = {'N', 'E', 'S', 'W'};
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
                if (dirs[d] == 'N') {
                    while (c--) {
                        if (isObs.count(convert(x, y + 1)))
                            break;
                        y++;
                    }
                } else if (dirs[d] == 'S') {
                    while (c--) {
                        if (isObs.count(convert(x, y - 1)))
                            break;
                        y--;
                    }
                } else if (dirs[d] == 'E') {
                    while (c--) {
                        if (isObs.count(convert(x + 1, y)))
                            break;
                        x++;
                    }
                } else if (dirs[d] == 'W') {
                    while (c--) {
                        if (isObs.count(convert(x - 1, y)))
                            break;
                        x--;
                    }
                }
                result = max(result, (x * x) + (y * y));
            }
        }
        // int result = pow(x, 2) + pow(y, 2);
        return result;
    }
};