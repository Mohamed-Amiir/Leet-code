class Solution {
public:
    int GCD(int x, int y){
        while(y != 0){
            int temp = y;
            y = x % y;
            x = temp;
        }
        return x;
    }
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
        return GCD(sumEven, sumOdd);
    }
};