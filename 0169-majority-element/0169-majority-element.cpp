class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> freq;
        int majority = -1;
        int most = 0;
        for(int i = 0;i < nums.size(); i++){
           freq[nums[i]]++;
           if(freq[nums[i]] > most){
             most = freq[nums[i]];
             majority = nums[i];
           }
           if(most > nums.size()/2){
            return majority;
           }
        }
        return -1;
    }
};