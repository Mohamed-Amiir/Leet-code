class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        
        // if(nums.size() == 2)
        //    return {(nums[0] % 2 == 0 && nums[1] % 2 != 0 ) || (nums[1] % 2 == 0 && nums[0] % 2 != 0 )};

        vector<int> wrong;
        for(int i = 1;i < nums.size();i++){
            if((nums[i] % 2 == 0 && nums[i-1] % 2 == 0)||(nums[i] % 2 != 0 && nums[i-1] % 2 != 0))
            {
                wrong.push_back(i);
            }
        }


        // cout << "WRONG: " <<endl;
        // cout << "WRONG.SIZE: " << wrong.size() << endl;
        // for(auto t:wrong){
        //     cout << t << " " << t+1 <<endl;
        // }


        vector<bool>result(queries.size(),true);
        int i = 0;
        for(auto q:queries){
            // if(q[0] == q[1]) continue;
            // else if(q[1] == q[0]+1){
            //     if((nums[q[0]] % 2 == 0 && nums[q[1]] % 2 != 0 ) || (nums[q[1]] % 2 == 0 && nums[q[0]] % 2 != 0 ))
            //     { 
            //         i++;
            //         continue;
            //     }
            //     else{ 
            //         result[i] = false;
            //         i++;
            //         continue;
            //     }
            // }

            int start = 0 ,end = wrong.size()-1;
            while(start <= end){
                int mid = start + (end-start)/2;
                if(wrong[mid] > q[0] && wrong[mid] <= q[1]){
    
                    result[i] = false;
                    break;
                }
                else if(wrong[mid] > q[1]){
                    end = mid -1;
                }
                else if(wrong[mid] <= q[0]){
                    start = mid + 1;
                }
            }
            i++;
        }
        return result;
    }
};