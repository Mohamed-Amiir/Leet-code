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
                    cout << "NewDig : " << dig << endl;
                    dig -= x.first;
                    res.push_back(x.second);
                    cout << "ROMAN: "<< x.second<<endl;
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
       
        map<char,int> values;
        values['I'] = 1;
        values['V'] = 5;
        values['X'] = 10;
        values['L'] = 50;
        values['C'] = 100;
        values['D'] = 500;
        values['M'] = 1000;

        string result = "";
        int temp = 1000;
        while(num != 0){
            int dig = (num / temp)*temp;
            cout << "dig : " << dig << endl;
            process(vals,result,dig);
            num = num % temp;
            temp = temp /10;
        }

        // filter result from 4 and 9

        // int c = 0;
        // string output = "";
        // string t = "";
        // t.push_back(result[0]);
        // for(int i=1;i < result.size();i++)
        // {
        //     if(result[i] != result[i-1]){
        //         if(c==5){
        //             if(t[0] == 'I'){

        //             }
        //         }
        //         else if(c==10)
        //         else output = output + t;
        //         t = "";c=0;
        //     }
        //     c++;
        //     t.push_back(result[i])
        //     if(i == result.size()-1){
        //         if(c==5)
        //         else if(c==10)
        //         else output = output + t;
        //         t = "";c=0;
        //     }
        // }
        // return output;
        return result;
    }
};