class Solution {
public:
    int hammingWeight(int n) {
        if(n == 0)
          return 0;
        int count = 0;
        count += n % 2; 
        return count += hammingWeight(n/2);
    }
};