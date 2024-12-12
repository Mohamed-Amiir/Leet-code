class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
         long long result = 0;
         priority_queue<int> pq(gifts.begin(), gifts.end());
         while(k--){
            int x = sqrt(pq.top());
            pq.pop();
            pq.push(x);
         }
         while(!pq.empty()){
            result += pq.top();
            pq.pop();
         }
         return result;
     }
};