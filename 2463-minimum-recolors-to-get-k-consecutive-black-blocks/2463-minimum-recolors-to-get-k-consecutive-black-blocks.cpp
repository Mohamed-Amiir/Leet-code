class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int l = 0, r = k - 1, i = 0,L = 0, R = 0, maxRow = 0, minW = 1e9,
            n = blocks.size(), w = 0;
        while (r < n) {
            if (l > r) {
                i++;
                l = i;
                r = l + k - 1;
                minW = min(minW, w);
                w = 0;
            } 
            else {
                if (blocks[l] == 'W')
                    w++;
                l++;
            }

        }

        return minW;
        // while (r < n) {
        //     if (blocks[r] == 'W') {
        //         maxRow = max(maxRow, c);
        //         if (maxRow == c) {
        //             L = l;
        //             R = r;
        //         }
        //         l = r + 1;
        //         r = l;
        //         c = 0;
        //     } else {
        //         r++;
        //         c++;
        //     }
        // }
        // maxRow = max(maxRow, c);
        // if (maxRow == c) {
        //     L = l;
        //     R = r;
        // }
        // R--;
        // cout << "MAX ROW: " << maxRow<<endl;
        // cout << "LEFT: " << L << " " << "RIGHT: " << R;

        // if(maxRow >= k)return 0;
        // int result = 0;
        // while(k < maxRow){

        // }
    }
};