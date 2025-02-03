class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int result = 0, c = 1, n = nums.size();
        if(n == 1)return 1;

        for(int i = 1; i < n;i++){
            if(nums[i] > nums[i-1])c++;
            else{
                result = max(c,result);
                c = 1;
            }
        }
        result = max(result,c);
        c = 1;
        for(int i = 1; i < n;i++){
            if(nums[i] < nums[i-1])c++;
            else{
                result = max(c,result);
                c = 1;
            }
        }
        result = max(result,c);


        return result;
    }
};