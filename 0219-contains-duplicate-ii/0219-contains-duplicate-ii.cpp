class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size() == 1)
           return false;
        for(int i = 0; i < nums.size();i++){
            int counter = k,j = i + 1;
            while(j < nums.size() && counter-- ){
                if(nums[i] == nums[j])
                   return true;
                j++;
            }
        }
        return false;
    }
};