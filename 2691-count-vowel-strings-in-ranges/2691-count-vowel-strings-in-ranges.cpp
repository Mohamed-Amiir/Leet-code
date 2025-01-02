class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<char> vol;
        vol.insert('a');
        vol.insert('e');
        vol.insert('o');
        vol.insert('i');
        vol.insert('u');
        
        vector<int> prefix; int c = 0;
        for(auto x : words){
            if(vol.count(x[0]) && vol.count(x.back()))c++;
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