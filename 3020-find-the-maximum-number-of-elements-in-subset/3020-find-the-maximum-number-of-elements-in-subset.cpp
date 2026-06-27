class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        int result = 0;
        if (freq[1] % 2 == 0) {
            result = freq[1] - 1;
        } else {
            result = freq[1];
        }
        freq.erase(1);
        for (auto p : freq) {
            int temp = 0;
            long long x = p.first;
            for (; freq.contains(x) && freq[x] > 1; x *= x) {
                temp += 2;
            }
            result = max(result, temp + (freq.contains(x) ? 1 : -1));
        }
        return result;
    }
};