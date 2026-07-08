public class Solution
{
    const long MOD = 1000000007;

    public int[] SumAndMultiply(string s, int[][] queries)
    {
        int n = s.Length;

        // prefix sum of all digits
        int[] digitSum = new int[n + 1];

        // number of non-zero digits before each position
        int[] nzPrefix = new int[n + 1];

        List<int> digits = new();

        for (int i = 0; i < n; i++)
        {
            int d = s[i] - '0';

            digitSum[i + 1] = digitSum[i] + d;
            nzPrefix[i + 1] = nzPrefix[i];

            if (d != 0)
            {
                digits.Add(d);
                nzPrefix[i + 1]++;
            }
        }

        int m = digits.Count;

        long[] pow10 = new long[m + 1];
        pow10[0] = 1;

        for (int i = 1; i <= m; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        long[] prefixValue = new long[m + 1];

        for (int i = 0; i < m; i++)
        {
            prefixValue[i + 1] = (prefixValue[i] * 10 + digits[i]) % MOD;
        }

        int[] ans = new int[queries.Length];

        for (int i = 0; i < queries.Length; i++)
        {
            int l = queries[i][0];
            int r = queries[i][1];

            // sum of digits
            long sum = digitSum[r + 1] - digitSum[l];

            // indices in digits[]
            int L = nzPrefix[l];
            int R = nzPrefix[r + 1] - 1;

            long x = 0;

            if (L <= R)
            {
                int len = R - L + 1;

                x = (prefixValue[R + 1]
                    - prefixValue[L] * pow10[len]) % MOD;

                if (x < 0)
                    x += MOD;
            }

            ans[i] = (int)((x * sum) % MOD);
        }

        return ans;
    }
}