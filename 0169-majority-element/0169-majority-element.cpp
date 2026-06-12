class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int c = 1 , n = nums.size(), target = n /2 ;
        for(int i = 1;i  <n;i++){
            if(nums[i] != nums[i-1]){
                c = 0;
            }
            c++;
            if(c > target)return nums[i];
        }
        if(c)return nums.back();
        return -1;
    }
};