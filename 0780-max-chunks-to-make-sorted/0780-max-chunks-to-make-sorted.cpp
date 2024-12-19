class Solution {
public:
    int maxChunksToSorted(const std::vector<int>& arr) {
        int max_so_far = 0;
        int chunks = 0;

        for (int i = 0; i < arr.size(); ++i) {
            max_so_far = std::max(max_so_far, arr[i]);
            // If the max value so far equals the current index, we can create a chunk
            if (max_so_far == i) {
                ++chunks;
            }
        }

        return chunks;
    }
};