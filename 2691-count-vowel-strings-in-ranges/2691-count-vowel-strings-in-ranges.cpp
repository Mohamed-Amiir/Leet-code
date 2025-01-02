class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_map<char,bool> vol;
        vol['a'] = 1;
        vol['e'] = 1;
        vol['o'] = 1;
        vol['i'] = 1;
        vol['u'] = 1;
        vector<int> prefix; int c = 0;
        for(auto x : words){
            if(vol[x[0]] && vol[x[x.size()-1]])c++;
            prefix.push_back(c);
        } 
        vector<int> result;

        for(auto q : queries){
            if(q[0] > 0) 
               result.push_back(prefix[q[1]] - prefix[q[0]-1]);
            else
               result.push_back(prefix[q[1]]);
        }
        return result;
    }
};