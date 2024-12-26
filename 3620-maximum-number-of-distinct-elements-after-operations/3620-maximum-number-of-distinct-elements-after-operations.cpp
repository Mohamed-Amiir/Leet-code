class Solution {
public:
    int bs(int left,int right, unordered_map<int,bool>& visited){
        int temp = INT_MIN;
        while(left <= right){
           int mid = left + (right-left)/2;
           if(!visited[mid]){
               temp = mid;
               right = mid - 1;
           }
           else if(visited[mid]){
            left = mid + 1;
           }
        }   
        return temp;
    }
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        unordered_map<int,bool> visited;
        unordered_set<int> result;
        for(int i = 0;i < nums.size();i++){
           int res = bs(nums[i]-k,nums[i]+k,visited);
        //    cout << res << endl;
           if(res != INT_MIN){
             visited[res] = 1;
             result.insert(res);
           }
        }
        return result.size();
    }
};