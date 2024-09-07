class Solution {
public:
vector<vector<bool>> visited;
vector<pair<int, int>> directions = { {0,-1},{0,1},{1,0},{-1,0} };

bool valid(int i, int j, vector<vector<char>>& board) {
	int rows = board.size();
	int cols = board[0].size();
	return i >= 0 && i < rows&& j >= 0 && j < cols;
}


pair<bool, vector<pair<int, int>>> BFS(int i, int j, vector<vector<char>>& board) {

	vector<pair<int, int>> oVertcies;
	bool flag = true;
	visited[i][j] = 1;
	queue<pair<int, int>> neighbors;
	neighbors.push({ i, j });

	while (!neighbors.empty()) {

		int curI = neighbors.front().first;
		int curJ = neighbors.front().second;
		oVertcies.push_back({ curI,curJ });
		neighbors.pop();

		for (auto direction : directions) {
			int newI = curI + direction.first;
			int newJ = curJ + direction.second;

			if (!valid(newI, newJ, board))
			{
				flag = false;
				continue;
			}
			//check if o
			if (board[newI][newJ] == 'O' && !visited[newI][newJ])
			{
				oVertcies.push_back({ newI,newJ });
				visited[newI][newJ] = 1;
				neighbors.push({ newI, newJ });
			}

			// NOW LETS CHECK NEIGHBORS : valid and = O and NOT visited
			/*if (valid(newI, newJ, board) && board[newI][newJ] == 'O' && !visited[newI][newJ]) {
				visited[newI][newJ] = 1;
				neighbors.push({ newI, newJ });
			}*/


		}
	}
	return { flag,oVertcies };
}
void paint(vector<pair<int, int>> O, vector<vector<char>>& board) {
	for (auto x : O) {
		board[x.first][x.second] = 'X';
	}
}

void solve(vector<vector<char>>& board) {

	int rows = board.size();
	int cols = board[0].size();

	visited = vector<vector<bool>>(rows, vector<bool>(cols, false));


	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (board[i][j] == 'O' && !visited[i][j]) {
				pair<bool, vector<pair<int, int>>> result = BFS(i, j, board);
				if (result.first)
				{
					paint(result.second, board);
				}
			}
		}
	}
}

};