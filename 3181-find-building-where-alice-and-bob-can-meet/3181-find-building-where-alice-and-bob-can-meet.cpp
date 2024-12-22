// class Solution {
// public:
//     int n, sparseTable[50010][20], logValues[50010];

//     int queryMaximum(int left, int right) {
//         int k = logValues[right - left + 1];
//         return max(sparseTable[left][k], sparseTable[right - (1 << k) + 1][k]);
//     }
//     int binarySearch(int l , int r, int maxHight, vector<int>& memo){
//         if(memo.back() <= maxHight || r == memo.size()) return -1;
//         int mid;
//         while(l < r){
//            mid = l + (r - l) / 2;
//            if(queryMaximum(r,mid) > maxHight){
//               r = mid;
//            }
//            else if(memo[mid] <= maxHight)
//               l = mid + 1;
//         }
//         if(l == memo.size())return -1;
//         return l;
//     }

//     vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
//         int n = heights.size();
//         vector<int> memo(n), result;
//        sparseTable[n][0] = 2e9;
//         logValues[0] = -1;
//         for (int i = 1; i <= n; i++) {
//             logValues[i] = logValues[i >> 1] + 1;
//         }
//         for (int i = 0; i < n; i++) {
//             sparseTable[i][0] = heights[i];
//         }
//         for (int i = 1; i < 20; i++) {
//             for (int j = 0; j + (1 << i) - 1 <= n; j++) {
//                 sparseTable[j][i] = max(sparseTable[j][i - 1], sparseTable[j + (1 << (i - 1))][i - 1]);
//             }
//         }

//         auto cmp = [](pair<int, int> a, pair<int, int> b) {
//             if (a.first == b.first) {
//                 return a.second > b.second; // Smaller second element has higher priority
//             }
//             return a.first < b.first; // Larger first element has higher priority
//         };


//         int cur = -1;
//         for(int i = n-1; i >= 0; i--){
//            cur = max(cur, heights[i]);
//            memo[i] = cur;
//         }
//         //////////////////
//         for(int x:memo){
//             cout << x << " ";
//         }
//         /////////////////
//         for(auto q : queries){
//            int left = q[0],right = q[1];
//            int h1 = heights[q[0]] , h2 = heights[q[1]];
//            int maxHight = max(h1,h2);
//            if(left > right) swap(left,right);
           
//            if(q[0] == q[1])
//               result.push_back(q[0]);
//            else if(h2 > h1)
//               result.push_back(q[1]);
        
//         //    else{
//         //         priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> getMaxHight(cmp);
//         //         //////// fill the pq with all element from h2 to n
//         //         for(int i = q[1] ; i< n;i++){
//         //             getMaxHight.push({heights[i],i});
//         //         }
//         //         ///////
                
//         //         if(getMaxHight.top().first < maxHight)
//         //            result.push_back(-1);
//         //         else
//         //            result.push_back(getMaxHight.top().second);
//         //    }
//            else{
//               /// now binary search for the most left higght higher than maxHight , left = h2 ,right = n
//               result.push_back(binarySearch(right,n,maxHight,memo));
//            }
           
//         }
//         return result;
//     }
// };
class Solution {
public:
    int n, sparseTable[50010][20], logValues[50010];

    int queryMaximum(int left, int right) {
        int k = logValues[right - left + 1];
        return max(sparseTable[left][k], sparseTable[right - (1 << k) + 1][k]);
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        sparseTable[n][0] = 2e9;
        logValues[0] = -1;
        for (int i = 1; i <= n; i++) {
            logValues[i] = logValues[i >> 1] + 1;
        }
        for (int i = 0; i < n; i++) {
            sparseTable[i][0] = heights[i];
        }
        for (int i = 1; i < 20; i++) {
            for (int j = 0; j + (1 << i) - 1 <= n; j++) {
                sparseTable[j][i] = max(sparseTable[j][i - 1], sparseTable[j + (1 << (i - 1))][i - 1]);
            }
        }
        int numQueries = queries.size();
        vector<int> results(numQueries);
        for (int queryIndex = 0; queryIndex < numQueries; queryIndex++) {
            int left = queries[queryIndex][0], right = queries[queryIndex][1];
            if (left > right) swap(left, right);
            if (left == right) {
                results[queryIndex] = left;
                continue;
            }
            if (heights[right] > heights[left]) {
                results[queryIndex] = right;
                continue;
            }
            int maxHeight = max(heights[right], heights[left]);
            int low = right, high = n, mid;
            while (low < high) {
                mid = (low + high) >> 1;
                if (queryMaximum(right, mid) > maxHeight) {
                    high = mid;
                } else {
                    low = mid + 1;
                }
            }
            results[queryIndex] = (low == n) ? -1 : low;
        }
        return results;
    }
};