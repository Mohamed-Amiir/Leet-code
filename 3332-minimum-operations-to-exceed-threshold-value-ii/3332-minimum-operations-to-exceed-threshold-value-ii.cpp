class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int c = 0;
        // sort(nums.begin(),nums.end());
        priority_queue<long long,vector<long long>,greater<long long>> q(nums.begin(),nums.end());
        // for(int x : nums){
        //     q.push(x);
        // }
        while( q.size()>=2 && q.top() < k){
            // printQ(q);
            int n = 2,x= q.top(),y;
            q.pop();
          if(!q.empty()){
            y = q.top();
            q.pop();
          }
          long long a = min(x,y),b = max(x,y);
           q.push(a*2 + b);
           c++;
        } 
        return c;
    }
};