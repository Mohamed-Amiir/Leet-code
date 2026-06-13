class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result = "";
        for (string word : words) {
            int wSum = 0;
            for (char c : word) {
                wSum += weights[c - 'a'];
            }
            wSum = wSum % 26;
            
            result.push_back(char(122-wSum));
        }
        return result;
    }
};