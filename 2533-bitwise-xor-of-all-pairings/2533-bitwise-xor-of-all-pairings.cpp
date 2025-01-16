class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xor1 = 0, xor2 = 0;
        
        // Compute XOR of all elements in nums1 and nums2
        for (int num : nums1) {
            xor1 ^= num;
        }
        for (int num : nums2) {
            xor2 ^= num;
        }
        
        // Calculate the result based on the parity of sizes
        int n1 = nums1.size(), n2 = nums2.size();
        int result = 0;
        if (n2 % 2 == 1) {
            result ^= xor1; // nums1 contributes
        }
        if (n1 % 2 == 1) {
            result ^= xor2; // nums2 contributes
        }
        
        return result;
    }
};
