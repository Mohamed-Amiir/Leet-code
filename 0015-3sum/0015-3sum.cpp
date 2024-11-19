class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() < 3) return result;
        sort(nums.begin(), nums.end());
        int zCounter =0 ;
        for(int x  : nums){
            if(x < 0||zCounter >= 3) break;
            else if(x == 0)zCounter++;
        }

////    -4 -1 -1 0 1 2

        for(int i = 0 ; i < nums.size() ; i++ ) {
            if( i > 0 && nums[i] == nums[i-1] )continue;
            int cur = nums[i] , a = i+1 , z = nums.size()-1;
            while (z > a)
            {
                if (nums[a] + cur + nums[z] > 0) {
                    z--;
                }
                else if (nums[a] + cur + nums[z] < 0) {
                    a++;
                }
                else {
                    result.push_back({ nums[a],cur,nums[z] });
                    while(z > a && nums[a] == nums[a+1])a++;
                    while(z > a && nums[z] == nums[z-1])z--;
                    a++;z--;
                }
            }
        }
       
        return result;
    }
};