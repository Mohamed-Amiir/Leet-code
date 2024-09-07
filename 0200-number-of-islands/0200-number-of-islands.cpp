class Solution {
public:
vector<vector<bool>> visited;
vector<pair<int, int>> directions = { {0,-1},{0,1},{1,0},{-1,0} };

bool valid(int i, int j, vector<vector<char>>& board) {
	int rows = board.size();
	int cols = board[0].size();
	return i >= 0 && i < rows&& j >= 0 && j < cols;
}


void BFS(int i, int j, vector<vector<char>>& board) {

	visited[i][j] = 1;
	queue<pair<int, int>> neighbors;
	neighbors.push({ i, j });

	while (!neighbors.empty()) {

		int curI = neighbors.front().first;
		int curJ = neighbors.front().second;
		neighbors.pop();

		for (auto direction : directions) {
			int newI = curI + direction.first;
			int newJ = curJ + direction.second;


			// NOW LETS CHECK NEIGHBORS : valid and = O and NOT visited
			if (valid(newI, newJ, board) && board[newI][newJ] == '1' && !visited[newI][newJ]) {
				visited[newI][newJ] = 1;
				neighbors.push({ newI, newJ });
			}


		}
	}

}


int numIslands(vector<vector<char>>& board) {
	int c = 0;
	int rows = board.size();
	int cols = board[0].size();

	visited = vector<vector<bool>>(rows, vector<bool>(cols, false));


	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (board[i][j] == '1' && !visited[i][j]) {
				c++;
				BFS(i,j,board);
			}
		}
	}
	return c;
}

};