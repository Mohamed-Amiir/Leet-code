class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int left = 0, right = 0;
        vector<int> result;
        int sum = 0,c = 0;
        
        while(left < nums.size()&&right <  nums.size()){
            sum += nums[right];
            c++;
            right++;
            if(sum >= target){
                result.push_back(c);

                while(sum >= target){
                   sum -= nums[left];
                   left++;
                   result.push_back(c);
                   c--;
                }
            }
        }
        

        if(result.empty())return 0;
        return *min_element(result.begin(),result.end());
    }
};