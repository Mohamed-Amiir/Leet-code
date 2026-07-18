class Solution {
public:

    // 4  , 8
    // 

    int GCD(int x, int y){
        while(x > 0){
          int temp = x;
          x = y % x;
          y = temp;
        }
        return y;
    }
    int findGCD(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        int mini = *min_element(nums.begin(),nums.end());
        return GCD(maxi,mini);
    }
};