class Solution {
public:
void rotate(vector<int>& nums, int k) {
	int n = nums.size();
	k = k % n;
	if (n != 1)
	{
		//reverse nums
		int i = 0, j = nums.size() - 1;
		while (j > i)
		{
			int temp = nums[i];
			nums[i] = nums[j];
			nums[j] = temp;
			i++; j--;
		}

		//reverse k of nums
		i = 0, j = k - 1;
		while (j > i)
		{
			int temp = nums[i];
			nums[i] = nums[j];
			nums[j] = temp;
			i++; j--;
		}
		//reverse the rest of nums
		i = k, j = nums.size() - 1;
		while (j > i)
		{
			int temp = nums[i];
			nums[i] = nums[j];
			nums[j] = temp;
			i++; j--;
		}

	}

}


};