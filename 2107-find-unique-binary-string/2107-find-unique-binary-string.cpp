class Solution {
public:
    void solve(int n,char bit,vector<string>& res,string& cur){
         if(cur.size() == n){
            res.push_back(cur);
            return;
         }
         cur.push_back(bit);
         int s = cur.size();

         solve(n,bit,res,cur);

        //  cur.pop_back();
        if(bit == '0')bit='1';
        else bit = '0';

        cur[s-1] = bit;
        solve(n,bit,res,cur);
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums[0].size();
        string cur = "";
        vector<string> result;
        unordered_set<string> NUMS;

        solve(n,'0',result,cur);
        cur = "";
        solve(n,'1',result,cur);


        for(auto x : nums){
            NUMS.insert(x);
        }

        for(auto x : result){
            cout << x << " ";
            if(NUMS.count(x) == 0)return x;
        }
        return "";

    }
};