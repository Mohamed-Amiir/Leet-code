class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char,int>counter,temp;
        for(auto s: words2){
            for(auto c : s){
                temp[c]++;
                counter[c] = max(counter[c],temp[c]);
            }
            temp.clear();
        }
        for(auto x : counter){
           cout << x.first << " " << x.second<< endl; 
           }
        vector<string> result;
        // bool flag = 1;
        for(auto s:words1){
            bool flag = 1;
            cout << "S :" <<s<<endl;
           for(auto x : counter){
             if(x.second > count(s.begin(),s.end(),x.first)){
                cout << "HELLO FROM BREAK , S = " << s << endl;
                flag = 0;
                break;
             }
           }
           if(flag)result.push_back(s);
        }
        
        return result;
    }
};