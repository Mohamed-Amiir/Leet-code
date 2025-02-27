class Solution {
public:
    int bs(vector<int>& arr, int target, int left) {
        int l = left, r = arr.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] == target)
                return mid;
            else if (arr[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1; // Target not found
    }

    int lenLongestFibSubseq(vector<int>& arr) {
        int result = 0;
        int n = arr.size();
        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                int a = arr[i];
                int b = arr[j];
                int current_len = 2;
                int current_j = j;
                int next = a + b;
                while (true) {
                    int idx = bs(arr, next, current_j + 1);
                    if (idx == -1) {
                        break;
                    }
                    current_len++;
                    a = b;
                    b = next;
                    current_j = idx;
                    next = a + b;
                }
                if (current_len > 2) {
                    result = max(result, current_len);
                }
            }
        }
        return result;
    }
};