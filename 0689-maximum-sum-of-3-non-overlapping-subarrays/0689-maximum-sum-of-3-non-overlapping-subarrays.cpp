class Solution {
public:
    long long getPref(int l, int r, vector<int>& pref) {
        if (l == 0) return pref[r];
        return pref[r] - pref[l - 1];
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pref(n, 0);

        // Build prefix sum array
        pref[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            pref[i] = pref[i - 1] + nums[i];
        }

        // Arrays to store the best indices and sums for left, middle, and right partitions
        vector<int> left(n, 0), right(n, 0);
        vector<long long> leftSum(n, 0), rightSum(n, 0);

        // Calculate the best left subarray sums and indices
        long long maxSum = getPref(0, k - 1, pref);
        leftSum[k - 1] = maxSum;
        left[k - 1] = 0;
        for (int i = k; i < n; ++i) {
            long long currentSum = getPref(i - k + 1, i, pref);
            if (currentSum > maxSum) {
                maxSum = currentSum;
                left[i] = i - k + 1;
            } else {
                left[i] = left[i - 1];
            }
            leftSum[i] = maxSum;
        }

        // Calculate the best right subarray sums and indices
        maxSum = getPref(n - k, n - 1, pref);
        rightSum[n - k] = maxSum;
        right[n - k] = n - k;
        for (int i = n - k - 1; i >= 0; --i) {
            long long currentSum = getPref(i, i + k - 1, pref);
            if (currentSum >= maxSum) {
                maxSum = currentSum;
                right[i] = i;
            } else {
                right[i] = right[i + 1];
            }
            rightSum[i] = maxSum;
        }

        // Find the maximum sum by iterating over the middle subarray
        vector<int> result(3, 0);
        maxSum = 0;
        for (int i = k; i <= n - 2 * k; ++i) {
            long long currentSum = leftSum[i - 1] + getPref(i, i + k - 1, pref) + rightSum[i + k];
            if (currentSum > maxSum) {
                maxSum = currentSum;
                result[0] = left[i - 1];
                result[1] = i;
                result[2] = right[i + k];
            }
        }

        return result;
    }
};