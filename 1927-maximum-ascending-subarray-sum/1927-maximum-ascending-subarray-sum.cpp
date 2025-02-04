class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int result = 0,c = nums[0],n = nums.size();
        for(int i = 1;i < n;i++){
            if(nums[i] <= nums[i-1]){
                result = max(c,result);
                c = 0;
            }
            c += nums[i];
        }
        result = max(c,result);
        return result;
    }
};