class Solution {
public:
    long long coloredCells(int n) {
        long long x = n;
        long long temp1 = x * x, temp2 = (x - 1) * (x - 1);
        long long result = temp1 + temp2;
        return result;
    }
};