class Solution {
public:
    void process(vector<pair<int,char>>& vals,string& res,int dig){
        if(dig == 0)return;
        if(dig == 4){res.append("IV");return;}
        else if(dig == 9){res.append("IX");return;}
        else if(dig == 40){res.append("XL");return;}
        else if(dig == 90){res.append("XC");return;}
        else if(dig == 400){res.append("CD");return;}
        else if(dig == 900){res.append("CM");return;}
        while(dig > 0){
            for(auto x: vals){
                if(x.first <= dig){
                    dig -= x.first;
                    res.push_back(x.second);
                    break;
                }
            } 
        }
    }
    string intToRoman(int num) {
        vector<pair<int,char>> vals;
        vals.push_back({1000,'M'});
        vals.push_back({500,'D'});
        vals.push_back({100,'C'});
        vals.push_back({50,'L'});
        vals.push_back({10,'X'});
        vals.push_back({5,'V'});
        vals.push_back({1,'I'});


        string result = "";
        int temp = 1000;
        while(num != 0){
            int dig = (num / temp)*temp;
            process(vals,result,dig);
            num = num % temp;
            temp = temp /10;
        }

        
        return result;
    }
};