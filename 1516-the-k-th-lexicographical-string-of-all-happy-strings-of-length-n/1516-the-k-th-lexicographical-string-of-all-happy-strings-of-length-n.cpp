#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void buildHappyStrings(string& current, vector<string>& result, int n, const vector<char>& chars) {
        if (current.size() == n) {
            result.push_back(current);
            return;
        }
        
        for (char c : chars) {
            if (current.empty() || c != current.back()) {
                current.push_back(c);
                buildHappyStrings(current, result, n, chars);
                current.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        vector<string> happyStrings;
        string current = "";
        vector<char> chars = {'a', 'b', 'c'};
        
        buildHappyStrings(current, happyStrings, n, chars);
        
        if (k > happyStrings.size()) {
            return "";
        }
        
        return happyStrings[k - 1];
    }
};