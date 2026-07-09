public class Solution {
    public bool[] PathExistenceQueries(int n, int[] nums, int maxDiff, int[][] queries) {
        int s = queries.Length;
        int[] components = new int[n];

        bool[] result = new bool[s];
        int curComp = 0;
        components[0] = 0;
        for(int i = 1 ;i < n; i++){
            if(nums[i] - nums[i-1] > maxDiff)curComp++;
            components[i] = curComp;
        }

        for(int i = 0 ;i < s; i++){
            result[i] = components[queries[i][0]] == components[queries[i][1]];
        }

        return result; 


    }
}