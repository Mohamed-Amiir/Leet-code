public class Solution {
    public long SumAndMultiply(int n) {
        long sum = 0;
        long newInt = 0;
        int place = 1;

        while(n > 0){

            int digit = n % 10;
            n = n / 10;
            sum += digit;
            if(digit != 0){
                newInt += (place * digit);
                place = place * 10;
            }
        }


        return  newInt * sum;
    }
}






















