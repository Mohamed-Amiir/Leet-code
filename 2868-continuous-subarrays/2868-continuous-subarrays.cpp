class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long result = 0;
        int l = 0; // Left pointer of the sliding window
        int r = 0; // Right pointer of the sliding window
        
        multiset<int> window; // To track the range of numbers in the current window
        
        while (r < nums.size()) {
            // Insert the current element into the window
            window.insert(nums[r]);
            
            // Check if the window satisfies the condition
            while (*window.rbegin() - *window.begin() > 2) {
                // Remove the element at the left pointer and increment the left pointer
                window.erase(window.find(nums[l]));
                l++;
            }
            
            // Count all subarrays ending at `r` and starting from indices `l` to `r`
            result += (r - l + 1);
            r++;
        }
        
        return result;
    }
};
