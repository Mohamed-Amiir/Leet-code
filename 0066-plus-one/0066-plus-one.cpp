class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int x = 0, n = digits.size()-1;bool flag = 0;
        if(digits[n] < 9){
           digits[n]++;
           return digits;
        }
        if(digits[n] == 9 && n ==0)
        {
            return {1,0};
        }
        while(n != 0 && digits[n] == 9){
            digits[n] = 0;
            n--;
            if(n == 0 && digits[n] == 9){
            digits[n] = 0;
               flag = 1;
               break;
            }
            if(digits[n] != 9){
                digits[n]++;
                return digits;
            } 
        }
        if(flag == 1){
            vector<int> result;
            result.push_back(1);
            int n = digits.size();
            while(n--){
                result.push_back(0);
            }
            return result;
        }
        return digits;
    }
};