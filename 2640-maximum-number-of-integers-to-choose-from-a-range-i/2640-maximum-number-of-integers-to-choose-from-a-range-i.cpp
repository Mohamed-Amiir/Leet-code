class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int c = 0 ,temp = 0;
        sort(banned.begin(),banned.end());
        int j = 0;
        for(int i = 1; i <= n ; i++){
            if(j < banned.size()){
                while(j < banned.size() && i > banned[j]) j++;
                if(i == banned[j])
                {
                    j++;
                    continue;
                }
                else{
                temp += i;
                if(maxSum >= temp)
                    c++;
                    else return c;
                }
            }
            else
            {
                temp += i;
                if(maxSum >= temp)
                    c++;
                else return c;
            }
        }
        return c;
        }
};