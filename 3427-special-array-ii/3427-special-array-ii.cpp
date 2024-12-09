class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        
        vector<int> wrong;
        for(int i = 1;i < nums.size();i++){
            if((nums[i] % 2 == 0 && nums[i-1] % 2 == 0)||(nums[i] % 2 != 0 && nums[i-1] % 2 != 0))
            {
                wrong.push_back(i-1);
            }
        }

        vector<bool>result(queries.size(),true);
        int i = 0;
        for(auto q:queries){
            int start = 0 ,end = wrong.size()-1;
            while(start <= end){
                int mid = start + (end-start)/2;
                if(wrong[mid] >= q[0] && wrong[mid] < q[1]){
                    result[i] = false;
                    break;
                }
                else if(wrong[mid] >= q[1]){
                    end = mid -1;
                }
                else if(wrong[mid] < q[0]){
                    start = mid + 1;
                }
            }
            i++;
        }
        return result;
    }
};