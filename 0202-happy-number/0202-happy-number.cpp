class Solution {
public:
    vector<int> getDigits(int n) {
        vector<int> res;
        while (n != 0) {
            int x = n % 10;
            n = n / 10;
            res.push_back(x);
        }
        return res;
    }

    bool isHappy(int n) {
        unordered_map<int,bool> visited; 
        while (n != 1 && !visited[n]) {
            visited[n] = true; 
            vector<int> digits = getDigits(n);
            int result = 0; 
            for (int d : digits) {
                result += d * d;
            }
            n = result;
        }
        return n == 1;
    }
};
