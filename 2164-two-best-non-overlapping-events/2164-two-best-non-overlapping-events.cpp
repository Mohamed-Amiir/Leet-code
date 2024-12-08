class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n =  events.size();
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0]; 
        });    
        int temp = 0,result =0 ,c = events.front()[2],eCounter = 1;
        vector<int> maxs(events.size());
        maxs[n-1] = events.back()[2];
        for(int i = n-2;i >= 0;i--){ 
            maxs[i] = max(events[i][2],maxs[i+1]);
        }

        for(int i= 0;i < events.size();i++){
            result = max(result,events[i][2]);

            int start = i+1, end = events.size()-1;
            while(start <= end){
                int mid = start + (end - start)/2;
                if(events[mid][0] > events[i][1]){
                    result = max(result, events[i][2] + maxs[mid]);
                    end = mid-1;

                }
                else {
                    start = mid+1;
                }
            }
        }
        return result;
    }
};