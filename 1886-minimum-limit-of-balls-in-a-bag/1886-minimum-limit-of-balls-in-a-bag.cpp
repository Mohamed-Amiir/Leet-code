class Solution {
public:
    bool canAchieveMaxPenalty(int maxPenalty, const vector<int>& nums, int maxOperations) {
        int operations = 0;
        for (int balls : nums) {
            // If balls in the bag exceed maxPenalty, calculate required splits
            if (balls > maxPenalty) {
                operations += (balls - 1) / maxPenalty; // Number of splits needed
            }
            // If operations exceed maxOperations, return false
            if (operations > maxOperations) {
                return false;
            }
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        // Binary search for the smallest maximum penalty
        int left = 1, right = *max_element(nums.begin(), nums.end());
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canAchieveMaxPenalty(mid, nums, maxOperations)) {
                right = mid;  // Try to minimize the maxPenalty
            } else {
                left = mid + 1;  // Increase the maxPenalty
            }
        }
        return left;
    }
};