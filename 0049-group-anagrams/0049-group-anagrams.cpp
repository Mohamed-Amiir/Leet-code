class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> mp;

       for(string& str: strs){
        string tmp = str;
        sort(str.begin(),str.end());
        mp[str].push_back(tmp);
       }
       vector<vector<string>> result;
       for(auto x : mp){
        result.push_back(x.second);
       }
       return result;
    }
};