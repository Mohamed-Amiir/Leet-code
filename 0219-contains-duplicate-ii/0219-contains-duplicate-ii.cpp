class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size() == 1)
           return false;
        unordered_map<int,pair<int,int>> n;
        unordered_map<int,bool> visited;
        for(int i = 0; i < nums.size();i++){
           if(visited[nums[i]]){
              n[nums[i]].second = i; 
              if(n[nums[i]].second-n[nums[i]].first <= k){
                return true;
              }
              n[nums[i]].first = i; 
              visited[nums[i]] = true;
           }
           else{
             n[nums[i]].first = i; 
             visited[nums[i]] = true;
           }
        }
        return false;
    }
};