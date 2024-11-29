class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int left = 0, right = 0;
        vector<int> result;
        int sum = 0,c = 0;
        
        while(left < nums.size()&&right <  nums.size()){
            sum += nums[right];
            c++;
            right++;
            if(sum >= target){
                cout << "Right : " << right << endl;
                result.push_back(c);

                // left = right;
                // c = 0;
                // sum  = 0;

                while(sum >= target){
                   cout << "Left : " << left << endl; 
                   sum -= nums[left];
                   left++;
                   result.push_back(c);
                   c--;
                }
            }
        }
        

        if(result.empty())return 0;
        return *min_element(result.begin(),result.end());;
    }
};