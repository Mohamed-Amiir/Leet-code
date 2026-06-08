class Solution {
public:

    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size(), l = 0, p = 0, r = 0;
        vector<int> left, piv, right, result;
        for(int x : nums){
            if(x < pivot)left.push_back(x);
            else if(x > pivot)right.push_back(x);
            else piv.push_back(x);
        }
        result.reserve(n);
        result.insert(result.end(),left.begin(),left.end());
        result.insert(result.end(),piv.begin(),piv.end());
        result.insert(result.end(),right.begin(),right.end());
        return result;
    }
};