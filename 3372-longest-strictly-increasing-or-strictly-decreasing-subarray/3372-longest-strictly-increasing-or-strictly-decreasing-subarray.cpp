class Solution {
public:
    bool check(int a,int b,int c,vector<int>& nums){
        return (nums[a] < nums[b] && nums[b] < nums[c]) ||(nums[a] > nums[b] && nums[b] > nums[c]);
    }
    int longestMonotonicSubarray(vector<int>& nums) {
        int result = 0, c = 1, n = nums.size();
        if(n == 1)return 1;
        else if (n == 2){
            if(nums[0] < nums[1] || nums[0] > nums[1]) return 2;
            else return 1;
        }

        for(int i = 1; i < n;i++){
            if(nums[i] > nums[i-1])c++;
            else{
                result = max(c,result);
                c = 1;
            }
        }
        result = max(result,c);
        c = 1;
        for(int i = 1; i < n;i++){
            if(nums[i] < nums[i-1])c++;
            else{
                result = max(c,result);
                c = 1;
            }
        }
        result = max(result,c);


        return result;
    }
};