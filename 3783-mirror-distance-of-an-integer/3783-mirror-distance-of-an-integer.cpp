class Solution {
public:
int rev(int x) {
    int res = 0;
    while (x > 0) {
        res = res * 10 + (x % 10);
        x /= 10;
    }
    return res;
}
    int mirrorDistance(int n) {
        return abs(n - rev(n));
    }
};