class Solution {
public:
    char processStr(string s, long long k) {
        const long long LIMIT = 1e15;

        int n = s.size();
        vector<long long> len(n);

        long long curLen = 0;

        // Forward pass: compute lengths
        for (int i = 0; i < n; i++) {
            char c = s[i];

            if ('a' <= c && c <= 'z') {
                curLen++;
            }
            else if (c == '*') {
                if (curLen > 0)
                    curLen--;
            }
            else if (c == '#') {
                curLen = min(LIMIT, curLen * 2);
            }
            // '%' => length unchanged

            len[i] = curLen;
        }

        if (k >= len.back())
            return '.';

        // Backward pass
        for (int i = n - 1; i >= 0; i--) {

            long long beforeLen = (i == 0 ? 0 : len[i - 1]);

            if ('a' <= s[i] && s[i] <= 'z') {

                if (k == beforeLen)
                    return s[i];
            }
            else if (s[i] == '#') {

                if (beforeLen > 0)
                    k %= beforeLen;
            }
            else if (s[i] == '%') {

                if (beforeLen > 0)
                    k = beforeLen - 1 - k;
            }
            else { // '*'
                // nothing
            }
        }

        return '.';
    }
};