class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        unordered_map<int,int> mp1,mp2;
        set<int> nums;
        for(auto x : nums1){
             mp1[x[0]] = x[1];
             nums.insert(x[0]);
        }
        for(auto x : nums2){
             mp2[x[0]] = x[1];
             nums.insert(x[0]);
        }
        vector<vector<int>> result;
        for(auto x : nums){
            result.push_back({x,mp1[x]+mp2[x]});
        }
        return result;
    }
};