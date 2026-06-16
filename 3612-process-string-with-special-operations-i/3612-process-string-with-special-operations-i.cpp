class Solution {
public:
    string processStr(string s) {
        string result = "";
        for(char c : s){
            if(islower(c))result.push_back(c);
            else if(c == '*' && result.size()> 0)result.pop_back();
            else if(c == '#')result += result;
            else if(c == '%')reverse(result.begin(),result.end());
        }
        return result;
    }
};