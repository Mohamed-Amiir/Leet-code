class Solution {
public:
//to be rechecked
    int waysToSplitArray(vector<int>& nums) {
        long long totalSum = 0; // Use long long to handle potential overflow
        for (int num : nums) {
            totalSum += num;
        }
        
        long long leftSum = 0;
        int count = 0;
        
        for (int i = 0; i < nums.size() - 1; ++i) { // Ensure at least one element remains on the right
            leftSum += nums[i];
            long long rightSum = totalSum - leftSum;
            if (leftSum >= rightSum) {
                ++count;
            }
        }
        
        return count;
    }
};
