class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int m = 1e9, x = 0;

        for (int a : nums) {
            m = min(m, a);
            x = max(x, a);
        }

        return 1LL * (x - m) * k;
    }
};