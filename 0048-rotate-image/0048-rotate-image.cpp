class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		vector<vector<int>> temp(matrix.size());
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix.size(); j++)
			{
				temp[i].push_back(matrix[j][i]);
			}
			reverse(temp[i].begin(), temp[i].end());
		}
		matrix = temp;
		temp.clear();
        //helllo 
	}
}; 