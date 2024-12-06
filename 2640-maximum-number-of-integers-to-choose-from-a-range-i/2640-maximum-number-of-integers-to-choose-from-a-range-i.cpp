class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int c = 0 ,temp = 0;
        unordered_map<int,bool> visited;
        for(int x : banned)
            visited[x] = true;
        // sort(banned.begin(),banned.end());
        int j = 0;
        for(int i = 1; i <= n ; i++){
            if(visited[i])continue;
            temp += i;
            if(maxSum >= temp)
                c++;
            else 
                return c;
        }
        return c;
    }
};