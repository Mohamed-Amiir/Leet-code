public class Solution {
    public long SumAndMultiply(int n) {
        long sum = 0;
        long newInt = 0;
        Stack<int> s = new();
        while(n > 0){

            int digit = n % 10;
            n = n / 10;
            sum += digit;
            if(digit != 0){
                s.Push(digit);
            }
        }

        while(s.Count > 0){
            int t = s.Pop();
            newInt = newInt * 10 + t;
        }

        return  newInt * sum;
    }
}






















