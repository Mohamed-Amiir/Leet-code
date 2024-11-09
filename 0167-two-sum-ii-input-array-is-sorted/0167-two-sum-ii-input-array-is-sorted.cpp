class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
    	int a = 0, z = numbers.size()-1;
	    while(a < z)
        {
            if (numbers[a] + numbers[z] > target)
                z--;
            else if (numbers[a] + numbers[z] < target)
                a++;
            else
                return { a+1,z+1 };
        }
        return {};
    }
};