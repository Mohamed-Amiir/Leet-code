class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0 ,r = 1;
        while(r < nums.size()){
            if(nums[l] == nums[r]){
                while(r < nums.size() &&nums[l] == nums[r]){
                    r++;
                }
            }
            else{
                l++;
                nums[l] = nums[r];
            }
        }     
        return l+1;
    }
};