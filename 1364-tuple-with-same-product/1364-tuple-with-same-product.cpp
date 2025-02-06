class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int result = 0, n = nums.size();
        unordered_map<int, short> mult;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                mult[nums[i] * nums[j]]++;
            }
        }

        for (auto x : mult) {
            short temp = x.second;

            if (temp > 1) {
                result += temp * (temp - 1) / 2;
            }
        }

        return result * 8;
    }
};