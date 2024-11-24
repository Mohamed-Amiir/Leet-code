class Solution {
public:
    string simplifyPath(string path) {
        stack<string> seq;
        vector<string> names;
        string word = "";
        for(char c : path){
            if(c == '/'){
                if(word == ""||word == "."){
                    word = "";
                    continue;
                }
                if(word == ".."&&!seq.empty()){
                    seq.pop();
                }
                else{
                    seq.push(word);
                }
               word = "";
            }
            else{
                word.push_back(c);
            }
        }

        if(word == ".."&&!seq.empty()){
                    seq.pop();
                }
        if(word != ".." && path.back() != '/'&& word != "."){
           seq.push(word);

        }

        while(!seq.empty()){
            if(seq.top()=="."||seq.top()==".."){
            seq.pop();
            continue;
            }
            names.push_back(seq.top());
            seq.pop();
            
           
        }
        reverse(names.begin(),names.end());
        string result = "";
        for(string n : names){
            result.push_back('/');
            result+=n;
        }
        if(result == "")
           return "/";
        else
           return result;
    
    }
};