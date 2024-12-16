class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        vector<int> nums;
        while(x != 0){
            int d = x % 10;
            x = x /10;
            nums.push_back(d);
        }
        int l = 0,r = nums.size()-1;
        while(l < r){
            if(nums[l] != nums[r])return false;
            l++;r--;
        }
        return true;
    }
};