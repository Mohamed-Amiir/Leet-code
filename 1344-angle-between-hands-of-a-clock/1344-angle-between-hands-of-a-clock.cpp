class Solution {
public:
    double angleClock(int hour, int minutes) {
        // each minute = 6 degress
        double hIndex = double(minutes) / 60 * 5 + ((hour % 12) * 5);
        double dif = abs(hIndex - minutes);
        double result1 = dif * 6 , result2 = 360 - result1;
        return min(result1,result2); 
    }
};