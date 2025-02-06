class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int result = 0;
        unordered_map<long long, int> mult;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                if (i == j)
                    continue;
                long long x = nums[i] * nums[j];
                mult[x]++;
            }
        }

        for (auto x : mult) {
            // cout << x.first << " " << x.second << endl;
            int temp = x.second ;

            if (temp > 1) {
                result += temp * (temp-1)/2;
                // temp % 2 == 1 ? result += temp/2 : result += temp / 2;
                // result += temp / 2;
            }
        }

        return result * 8;
    }
};