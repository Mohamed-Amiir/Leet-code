class Solution {
public:
    vector<vector<int>> stMax, stMin;
    vector<int> lg;

    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        buildSparseTables(nums);

        auto value = [&](int l, int r) -> long long {
            int len = r - l + 1;
            int j = lg[len];

            int mx = max(stMax[j][l],
                         stMax[j][r - (1 << j) + 1]);

            int mn = min(stMin[j][l],
                         stMin[j][r - (1 << j) + 1]);

            return 1LL * mx - mn;
        };

        using T = tuple<long long, int, int>;
        priority_queue<T> pq;

        // أكبر عنصر من كل سلسلة
        for (int l = 0; l < n; l++) {
            pq.push({value(l, n - 1), l, n - 1});
        }

        long long ans = 0;

        while (k--) {
            auto [val, l, r] = pq.top();
            pq.pop();

            ans += val;

            if (r > l) {
                pq.push({value(l, r - 1), l, r - 1});
            }
        }

        return ans;
    }

private:
    void buildSparseTables(vector<int>& nums) {
        int n = nums.size();

        lg.resize(n + 1);
        lg[1] = 0;

        for (int i = 2; i <= n; i++) {
            lg[i] = lg[i / 2] + 1;
        }

        int K = lg[n] + 1;

        stMax.assign(K, vector<int>(n));
        stMin.assign(K, vector<int>(n));

        for (int i = 0; i < n; i++) {
            stMax[0][i] = nums[i];
            stMin[0][i] = nums[i];
        }

        for (int j = 1; j < K; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                stMax[j][i] = max(
                    stMax[j - 1][i],
                    stMax[j - 1][i + (1 << (j - 1))]
                );

                stMin[j][i] = min(
                    stMin[j - 1][i],
                    stMin[j - 1][i + (1 << (j - 1))]
                );
            }
        }
    }
};