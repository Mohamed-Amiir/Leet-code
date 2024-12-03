class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 1||s.size()==0)return s.size();
        int a = 0,z=0;
        int c =0;
        vector<int> results;
        unordered_map<char,bool> mp;
        while(z < s.size()){
            if(mp[s[z]] == 1){
                results.push_back(c);
                a++;
                z=a;
                c = 0;
                mp.clear();
            }
            mp[s[z]] = 1;
            c++;
            z++;
        }
        // for(int i = 0; i < s.size();i++){
        //     if(mp[s[i]] == 1){
        //         results.push_back(c);
        //         c = 0;
        //         mp.clear();
        //     }
        //     mp[s[i]] = 1;
        //     c++;
        // }
        results.push_back(c);
        return *max_element(results.begin(),results.end());
    }
};