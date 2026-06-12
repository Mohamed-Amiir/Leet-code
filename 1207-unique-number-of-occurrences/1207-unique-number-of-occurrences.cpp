class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> freq;
        unordered_map<int,bool> uniqe;
        for(int x : arr){
            freq[x]++;
        }
        for(auto p : freq){
            if(uniqe[p.second])return false;
            uniqe[p.second] = true;
        }
        return true;
    }
};