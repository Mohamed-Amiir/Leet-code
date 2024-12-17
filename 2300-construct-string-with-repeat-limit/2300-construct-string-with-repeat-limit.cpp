class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
    // Frequency map
    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }

    // Max-heap to store characters in lexicographical order
    priority_queue<pair<char, int>> maxHeap;
    for (auto& [ch, count] : freq) {
        maxHeap.push({ch, count});
    }

    string result;

    while (!maxHeap.empty()) {
        // Get the largest character
        auto [char1, count1] = maxHeap.top();
        maxHeap.pop();

        // Determine how many times to append this character
        int appendCount = min(count1, repeatLimit);
        result.append(appendCount, char1);

        // If there are still occurrences left
        int remaining1 = count1 - appendCount;

        if (remaining1 > 0) {
            if (maxHeap.empty()) {
                // No other characters to break the sequence
                break;
            }

            // Use the next largest character to break the sequence
            auto [char2, count2] = maxHeap.top();
            maxHeap.pop();
            result.push_back(char2);
            count2--;

            // Reinsert both characters if they have remaining occurrences
            if (count2 > 0) {
                maxHeap.push({char2, count2});
            }
            maxHeap.push({char1, remaining1});
        }
    }

    return result;
}
};