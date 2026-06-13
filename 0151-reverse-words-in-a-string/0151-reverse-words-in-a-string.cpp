class Solution {
public:
    string reverseWords(string s) {
        stack<string> rev;
        stringstream ss(s);
        string word;
        while(ss>>word){
            rev.push(word);
        }
        string result = "";
        while(!rev.empty()){
            result += (rev.top() + ' ');
            rev.pop();
        }
        result.pop_back();
        return result;
    }
};