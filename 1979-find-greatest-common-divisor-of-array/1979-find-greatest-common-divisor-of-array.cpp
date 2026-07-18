class Solution {
public:


    int GCD(int x, int y){
        while(x > 0){
          int temp = x;
          x = y % x;
          y = temp;
        }
        return y;
    }
    int findGCD(vector<int>& nums) {
        int maxi = 0;
        int mini = 1001;

        for(int x : nums){
            maxi = max(maxi,x);
            mini = min(mini,x);
        }

        return GCD(maxi,mini);
    }
};