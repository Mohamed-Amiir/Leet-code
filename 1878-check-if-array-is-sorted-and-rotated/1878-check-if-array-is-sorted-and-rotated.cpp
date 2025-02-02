class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> temp = nums;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            bool flag = 1;
            for (int j = 0; j < n; j++) {
                if (temp[j] != nums[(j + i) % n]){
                    flag = 0;
                    break;
                }
            }
            if(flag)return true;
        }
        return false;
    }
};