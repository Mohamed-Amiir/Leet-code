class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_pq;
        for(int i = 0; i < nums.size(); i++){
            min_pq.push({nums[i],i});
        }
        while(k--){
            pair<int,int> x = min_pq.top();
            nums[x.second] = x.first * multiplier;
            x.first = x.first * multiplier;
            min_pq.pop();
            min_pq.push(x);
        }
        return nums;
    }
};