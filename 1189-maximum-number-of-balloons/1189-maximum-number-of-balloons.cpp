class Solution {
public:
    int maxNumberOfBalloons(string text) {
        string target = "balloon";
        unordered_map<char,int>freq,minFreq;
        for(char c : target){
            minFreq[c]++;
        }
        for(char c : text){
           freq[c]++;
        }
        int result = 1e9;
        for(char c : target){
            result = min(result,freq[c] / minFreq[c]);
        }
        return result;

    }
};