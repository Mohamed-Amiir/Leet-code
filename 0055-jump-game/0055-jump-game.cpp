class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n <=1)return true;
        int x = 0;
        for(int i = 0;i < n ;i++){
            if(i > x)return false;
            x = max(x,i+nums[i]);
            if(x == n-1)return true;
        }
        if(x > n-1)return true;
        return false;
    }
};