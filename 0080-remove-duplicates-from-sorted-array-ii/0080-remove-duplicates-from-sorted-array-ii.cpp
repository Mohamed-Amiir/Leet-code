class Solution {
public:

int removeDuplicates(vector<int>& nums) {
	int dCounter = 0;
	int nCounter = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		nCounter++;
		if (i + 1 == nums.size() || (i + 1 != nums.size() && nums[i] != nums[i + 1]))
		{
			if (nCounter > 2)
			{
				dCounter += nCounter - 2;
			}
			nCounter = 0;
		}
		
		if (dCounter != 0 && nCounter < 3)
		{
            nums[i - dCounter] = nums[i];
		}
	}
	return nums.size() - dCounter;
}
};