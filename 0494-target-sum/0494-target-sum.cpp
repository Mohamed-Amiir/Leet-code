class Solution {
public:
    
    int solve(int i, int curTarget, vector<int>& nums, int target) {
        if (i == nums.size()) {
            if (curTarget == target)return 1 ;
            else return 0;
        }

        int blus = solve(i+1,curTarget + nums[i],nums,target);
        int minus = solve(i+1,curTarget - nums[i],nums,target);

        return blus + minus;
        // if(curTarget == 0) return 1;
        // curTarget -= nums.back();
        // nums.pop_back();
        // return solve(nums,curTarget);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0,0,nums,target);
    }
};