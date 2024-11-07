class Solution {
public:
   
    string addBinary(string a, string b) {
        string result = "";
        char carry = '0';
        int i = a.size()-1,j = b.size()-1;

        while (i >= 0 || j >= 0 || carry != '0'){
            char A = (i >= 0) ? a[i] : '0';
            char B = (j >= 0) ? b[j] : '0';
            int c = (A =='1') + (B == '1') + (carry == '1');
            c % 2 == 0 ? result+='0' : result+='1';
            if(c >= 2)
               carry = '1';
            else
               carry = '0';
            
            i--;
            j--;

        }

      reverse(result.begin(), result.end());
      return result;
    }
};