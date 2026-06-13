class Solution {
public:
    string reverseWords(string s) {
        stack<string> rev;
        stringstream ss(s);
        string word;
        string result = "";
        // while(ss>>word){
        //     rev.push(word);
        // }
        // while(!rev.empty()){
        //     result += (rev.top() + ' ');
        //     rev.pop();
        // }
        // result.pop_back();
        // return result;

        int l = 0;
        while (l < s.size()) {
            if (s[l] == ' ') {
                l++;
            } else {
                string word = "";
                while ( l < s.size() && s[l] != ' ') {
                    word.push_back(s[l]);
                    l++;
                }
                rev.push(word);
            }
        }
        while (!rev.empty()) {
            result += (rev.top() + ' ');
            rev.pop();
        }
        result.pop_back();
        return result;
    }
};