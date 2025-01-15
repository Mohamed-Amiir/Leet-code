class Solution {
public:


int countSetBits(int n) {
    return __builtin_popcount(n);
}

int minimizeXor(int num1, int num2) {
    int num2SetBits = countSetBits(num2); // Number of set bits in num2
    int result = 0;

    // Set bits in result to match num1's most significant bits
    for (int i = 31; i >= 0 && num2SetBits > 0; --i) {
        if (num1 & (1 << i)) { // If the ith bit in num1 is set
            result |= (1 << i); // Set the ith bit in result
            --num2SetBits;      // Decrease required set bits
        }
    }

    // If we still need more set bits, set them starting from LSB
    for (int i = 0; i <= 31 && num2SetBits > 0; ++i) {
        if (!(result & (1 << i))) { // If the ith bit in result is not set
            result |= (1 << i);     // Set the ith bit in result
            --num2SetBits;          // Decrease required set bits
        }
    }

    return result;
}

};