class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
	   uint32_t result = 0;
       
        for (int i = 0; i < 32; i++) {
            result = result << 1;
            uint32_t a = n & 1;
            result = result | a;
            n = n >> 1;
        }

	return result;
    }
};