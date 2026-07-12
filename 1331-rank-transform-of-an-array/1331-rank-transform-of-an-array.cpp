class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int>result (n);
        unordered_map<int,int> rank;
        vector<int> temp = arr;
        sort(arr.begin(),arr.end());
        int curRank = 1;
        for(int x : arr){
            if(rank.count(x) > 0){
               continue;
            }
            rank[x] = curRank;
            curRank++;
        }
        int i = 0;
        for(int x : temp){
            result[i] = rank[x];
            i++;
        }
        return result ;
        // int maxi = 0, mini = 0,tempMax = -1,tempMin = 1e9;
        // int curRank = 0;
        // for(int x : arr){
        //    curRank++;
        //    if(x > tempMax){
        //       maxi = curRank;
        //    }else if(x < tempMin){
        //     mini = curRank;
        //    }
           
           

        // }
    }
};