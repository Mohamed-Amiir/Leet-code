class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> counter(26,0);
        // unordered_map<char,int>counter,temp;
        for(auto s: words2){
            vector<int> temp(26,0);
            for(auto c : s){
                temp[c-'a']++;
                counter[c-'a'] = max(counter[c-'a'],temp[c-'a']);
            }
        }

        vector<string> result;
        // bool flag = 1;
        for(auto s:words1){
            bool flag = 1;
           for(int i=0;i<26 ;i++){
             if(counter[i] > count(s.begin(),s.end(),'a'+i)){
                flag = 0;
                break;
             }
           }
           if(flag)result.push_back(s);
        }
        
        return result;
    }
};