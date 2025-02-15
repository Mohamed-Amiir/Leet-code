

class Solution {
public:
    void partitionDigits(vector<int>& digits, int index, vector<int>& current, vector<vector<int>>& result) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        int num = 0;
        for (int i = index; i < digits.size(); ++i) {
            num = num * 10 + digits[i];
            current.push_back(num);
            partitionDigits(digits, i + 1, current, result);
            current.pop_back();
        }
    }

    vector<vector<int>> getAllPartitions(vector<int>& digits) {
        vector<vector<int>> result;
        vector<int> current;
        partitionDigits(digits, 0, current, result);
        return result;
    }

    bool solve(int x) {
        if (x == 1) return true;
        long long y = (long long)x * x;
        vector<int> digits;
        while (y > 0) {
            digits.push_back(y % 10);
            y /= 10;
        }
        reverse(digits.begin(), digits.end()); // Correct the order of digits

        vector<vector<int>> partitions = getAllPartitions(digits);
        for (auto& p : partitions) {
            int total = 0;
            for (int num : p) {
                total += num;
            }
            if (total == x) {
                return true;
            }
        }
        return false;
    }

    int punishmentNumber(int n) {
        int result = 0;
        for (int i = 1; i <= n; ++i) {
            if (solve(i)) {
                result += i * i;
            }
        }
        return result;
    }
};