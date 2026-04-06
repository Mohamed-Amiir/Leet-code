class Solution {
public:
    string convert(int x, int y) {
        string s = "";
        if (x < 0)
            s += '-';
        char c = x + '0';
        s += c;
        if (x < 0)
            s += '-';
        c = y + '0';
        s += c;
        return s;
    }
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<string, bool> isObs;
        for (auto o : obstacles) {
            isObs[convert(o[0], o[1])] = 1;
        }
        int x = 0, y = 0, result = 0;
        vector<char> dirs = {'N', 'E', 'S', 'W'};
        int d = 0;
        int i = 1;
        for (int c : commands) {
            // cout << "ITERATION: " << i << endl;
            // i++;
            // cout << "DIRECTION: " << dirs[d]  << endl;
            // cout << "FROM: " << x << " , " << y << endl;
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
                        if (isObs[convert(x, y + 1)])
                            break;
                        y++;
                    }
                } else if (dirs[d] == 'S') {
                    while (c--) {
                        if (isObs[convert(x, y - 1)])
                            break;
                        y--;
                    }
                } else if (dirs[d] == 'E') {
                    while (c--) {
                        if (isObs[convert(x + 1, y)])
                            break;
                        x++;
                    }
                } else if (dirs[d] == 'W') {
                    while (c--) {
                        if (isObs[convert(x - 1, y)])
                            break;
                        x--;
                    }
                }
                // cout << "TO: " << x << " , " << y << endl;

                result = max(result, (x * x) + (y * y));
            }
        }
        // int result = pow(x, 2) + pow(y, 2);
        return result;
    }
};