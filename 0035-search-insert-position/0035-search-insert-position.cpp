class Solution {
public:
int searchInsert(vector<int>& nums, int target) {
    int start = 0, end = nums.size() - 1;
    int mid = 0;
    while (start <= end) {
        mid = start + (end - start) / 2;

        if (nums[mid] == target) {
            return mid; // Found the target
        }
        else if (nums[mid] < target) {
            start = mid + 1; // Search in the right half
        }
        else {
            end = mid - 1; // Search in the left half
        }
    }
    
    return start; // Position where target would be inserted
}


};