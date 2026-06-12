class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<int> signture(26);
        unordered_map<string, vector<string>> group;

        for (string s : strs) {
            vector<int> curSign = signture;
            for (char c : s) {
                curSign[c - 'a']++;
            }
            string strSign = "";
            for(int x : curSign){
                strSign += "#" + to_string(x);
            }
            group[strSign].push_back(s);
        }
        vector<vector<string>> result;
        for (auto p : group) {
            result.push_back(p.second);
        }

        return result;
    }
};