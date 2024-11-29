class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int left = 0, right = 0;
         int  result = 1e9;
        int sum = 0,c = 0;
        
        while(left < nums.size()&&right <  nums.size()){
            sum += nums[right];
            c++;
            right++;
            if(sum >= target){
                result = min(c,result);
                while(sum >= target){
                   sum -= nums[left];
                   left++;
                   result = min(c,result);

                   c--;
                }
            }
        }
        
        if(result == 1e9)return 0;
        return result;
    }
};