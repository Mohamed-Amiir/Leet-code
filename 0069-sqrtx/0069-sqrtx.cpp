class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1) return x;
        int left = 0,right = x;
        for(int i =2;i < 46341;i++){
            if ( i <= x/i && i+1 > x/(i+1)) return i;
        }
        return 1;
    }
};
// 0    8  => 4
// 0    4  => 3
// 0    3  => 1
// 2    3  => 