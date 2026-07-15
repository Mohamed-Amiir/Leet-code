class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = 0, sumEven = 0, i = 1;
        while (n) {
            if (i % 2 == 0) {
                sumEven += i;
                n--;
            } else
                sumOdd += i;
            i++;
        }
        return gcd(sumEven, sumOdd);
    }
};