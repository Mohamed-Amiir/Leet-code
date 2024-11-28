class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 1 && nums[0] == target) return {0,0};      
        int left = 0,right = nums.size()-1,mid= 0;
        bool flag = false;
        while(left <= right){
            mid = left + (right - left) / 2;
            if(nums[mid] > target)
                right = mid-1;
            else if(nums[mid] < target)
                left = mid+1;
            else{
                flag = true;
                break;
            }
        }
        left = mid,right = mid;
        if(flag){
          while(right < nums.size()-1 && nums[right+1] == target){
                right++;
          }
          while(left > 0 && nums[left-1] == target){
                left--;
          }

          return {left,right};
        }
        else{
            return {-1,-1};
        }
    }
};
