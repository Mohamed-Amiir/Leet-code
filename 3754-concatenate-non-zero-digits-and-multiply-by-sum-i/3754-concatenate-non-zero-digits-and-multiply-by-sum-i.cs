public class Solution {
    public long SumAndMultiply(int n) {
        long result = 1;
        long sum = 0;
        long newInt = 0;
        Stack<int> s = new Stack<int>();
        while(n > 0){

            var digit = n % 10;
            n = n / 10;
            sum += digit;
            if(digit != 0){
                s.Push(digit);
            }
        }

        while(s.Count > 0){
            var t = s.Pop();
            Console.WriteLine(t);
            newInt = (newInt * 10)+t;
        }
        result = newInt * sum;
        return result;
    }
}






















