class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1)return nums[0];
        unordered_map<int,int> dp;
        int p0 = nums[0];
        int p1 = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {

            int take = nums[i] + p0;

            int skip = p1;

            int current = max(take, skip);
            p0 = p1;
            p1 = current;
        }
        return p1;
    }
};