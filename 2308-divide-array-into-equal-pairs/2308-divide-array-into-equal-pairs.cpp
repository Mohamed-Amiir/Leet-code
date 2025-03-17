class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int>numsCounter;
        for(int x : nums){
            numsCounter[x]++;
        }
        for(auto x : numsCounter){
            if(x.second % 2 != 0)return false;
        }
        return true;
    }
};