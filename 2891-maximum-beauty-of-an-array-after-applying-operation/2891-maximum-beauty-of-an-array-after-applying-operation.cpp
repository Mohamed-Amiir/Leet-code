class Solution {
public:
    pair<int,int> operation(int x,int k){
        return {x-k,x+k};
    }
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();

        vector<pair<int ,bool>> points;

        for(int i=0;i < n;i++){
           pair<int,int> range = operation(nums[i],k);
           points.push_back({range.first,true});
           points.push_back({range.second+1,false});

        }
        sort(points.begin(),points.end());
        int result = 0,c=0;
        for(auto p : points){
            if(p.second){
                c++;
            }
            else{
                c--;
            }
            result = max(result,c);
        }
        return result;
    }
};