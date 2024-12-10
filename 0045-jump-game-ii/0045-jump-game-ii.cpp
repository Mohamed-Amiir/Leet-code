class Solution {
public:
    // int maxMove(vector<int>& input,int a){
    //     int result = 0;
    //     if(result == input.size()-1) return result;
    //     int cur = input[a+1];
    //     int j;
    //     for(j = a+1; j <= input[a]+a ;j++){
    //         if(input[j] >= cur){
    //            result = j;
    //            cur = input[j];
    //         }
    //         if(j == input.size()-1)return j;
    //     }
    //     return result;
    // }
    // int jump(vector<int>& nums) {
    //     int c = 0,i = 0;
    //     while(i < nums.size()-1){
    //        i = max(i,i+nums[i])
    //        c++;
    //     }
    //     return c;
    // }

    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;  // No jumps needed if there's only one element.

        int jumps = 0;  // Number of jumps made so far.
        int currentEnd = 0;  // The farthest point reachable with the current number of jumps.
        int farthest = 0;  // The farthest point reachable in the next jump.

        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + nums[i]);

            // If we reach the end of the current jump's range, we need to jump.
            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;

                // If the currentEnd reaches or exceeds the last index, we are done.
                if (currentEnd >= n - 1) break;
            }
        }

        return jumps;
    }
};