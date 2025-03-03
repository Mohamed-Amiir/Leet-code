class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
       vector<int> before,mid,after,result;
       for(auto x :nums){
        if(x > pivot)after.push_back(x);
        else if(x < pivot)before.push_back(x);
        else mid.push_back(x);
       }
       result.insert(result.end(),before.begin(),before.end());
       result.insert(result.end(),mid.begin(),mid.end());
       result.insert(result.end(),after.begin(),after.end());
       return result;
    }
};