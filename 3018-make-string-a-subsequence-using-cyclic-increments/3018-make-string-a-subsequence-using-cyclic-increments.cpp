class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
          int n = str2.size();
          int i = 0,j = 0 ;
          while(i < str1.size() && j < n){
            
            char temp = str1[i];
            if(temp == 122)temp = 97;
            else temp++;

            if(str1[i] == str2[j] || temp == str2[j] ){
                i++;
                j++;
            }
            else i++;
          }


          return j == n;
    }
};