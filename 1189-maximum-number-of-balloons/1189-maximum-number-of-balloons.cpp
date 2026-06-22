class Solution {
public:
    int maxNumberOfBalloons(string text) {
        string target = "balloon";
        int result = 1e9;
        unordered_map<char, int> freq, minFreq;

        // for(char c : target){
        //     minFreq[c]++;
        // }
        for (char c : text) {
            freq[c]++;
        }
        // for(char c : target){
        //     result = min(result,freq[c] / minFreq[c]);
        // }

        return min({freq['b'], freq['a'], freq['l'] / 2, freq['o'] / 2,
                   freq['n']});
    }
};