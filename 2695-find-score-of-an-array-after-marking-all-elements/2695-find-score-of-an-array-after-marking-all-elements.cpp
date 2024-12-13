class Solution {
public:
        long long findScore(vector<int>& nums) {
        vector<bool> marked(100001, false);

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> min_heap;
        for(int i  = 0;i < nums.size() ; i++){
            min_heap.push({nums[i],i});
        }

        long long result = 0;
        int c = 0;

        while (min_heap.size()) {
            pair<int,int> x = min_heap.top();
            min_heap.pop();
         
            int val = x.first,ind = x.second;

            if (!marked[ind]) {
                result += val;
                marked[ind] = true;
                c++;
                if (ind < nums.size() - 1) {
                    c++;
                    marked[ind + 1] = true;
                }
                if (ind >= 1) {
                    c++;
                    marked[ind - 1] = true;
                }
            }
        }
        return result;
    }

};