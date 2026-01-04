class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int result = 0;
        for (int x : nums) {
            int c = 0, sum = 0;

            for (int i = 1; i <= sqrt(x); i++) {
                if (x % i == 0) {
                    c++;
                    sum += i;
                    if (i * i != x) {
                        c++;
                        sum += x/i;
                    }
                }
            }
            if (c == 4) {
              result += sum;
            }
        }
        return result;
    }
};