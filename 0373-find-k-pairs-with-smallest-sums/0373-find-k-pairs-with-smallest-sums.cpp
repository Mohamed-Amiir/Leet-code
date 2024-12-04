class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        if (nums1.empty() || nums2.empty() || k <= 0) return result;

        // Min-heap to store pairs with their sums
        auto compare = [&](pair<int, int> a, pair<int, int> b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> minHeap(compare);

        // Push the first row of pairs (nums1[0] with all nums2 elements)
        for (int j = 0; j < nums2.size() && j < k; ++j) {
            minHeap.push({0, j});
        }

        // Extract k pairs with the smallest sums
        while (k-- > 0 && !minHeap.empty()) {
            auto [i, j] = minHeap.top();
            minHeap.pop();
            result.push_back({nums1[i], nums2[j]});

            // Push the next pair in the same row
            if (i + 1 < nums1.size()) {
                minHeap.push({i + 1, j});
            }
        }

        return result;
    }
};

