class Solution {
public:
    int getDigSum(int x) {
        int res = 0;
        while (x > 0) {
            int d = x % 10;
            x = x / 10;
            res += d;
        }
        return res;
    }

    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> digits(n);
        unordered_map<int, vector<int>> indOfSum;
        bool flag = 0;
        for (int i = 0; i < n; i++) {

            int temp = getDigSum(nums[i]);

            if (indOfSum[temp].size() < 2)
                indOfSum[temp].push_back(i);
            else {
                int t1 = nums[i] - nums[indOfSum[temp][0]];
                int t2 = nums[i] - nums[indOfSum[temp][1]];
                if (nums[i] > nums[indOfSum[temp][0]] ||
                    nums[i] > nums[indOfSum[temp][1]]) {
                    if (t1 > t2)
                        indOfSum[temp][0] = i;
                    else
                        indOfSum[temp][1] = i;
                }
            }

            if (indOfSum[temp].size() > 1)
                flag = 1;
        }
        if (!flag)
            return -1;

        for (auto x : indOfSum) {
            cout << "SUM " << x.first << endl;
            for (auto a : x.second) {
                cout << a << " ";
            }
            cout << endl;
        }

        int result = 0;
        for (auto x : indOfSum) {

            int s = x.second.size();
            if (s > 1) {
                result = max(result, nums[x.second[0]] + nums[x.second[1]]);
            }
        }
        return result;
    }
};