class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1) return x;
        int left = 0,right = x;
        while (left <= right){
            int mid = left + (right - left )/2;

            if ( mid <= x/mid && mid+1 > x/(mid+1)) return mid;
            else if (mid > x/mid ) 
               right = mid-1;
            else 
               left = mid+1;

        }
        return -1;
    }
};
// 0    8  => 4
// 0    4  => 3
// 0    3  => 1
// 2    3  => 