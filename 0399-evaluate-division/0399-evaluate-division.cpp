class Solution {
public:

	double BFS(map<string, vector<pair<string, double>>> graph, string s1, string s2) {
		map<string, bool>visited;
		queue<pair<string, double>> q;
		q.push({ s1,1 });

		while (!q.empty())
		{
			string curNode = q.front().first;
			double curRes = q.front().second;

			visited[curNode] = true;
			q.pop();

			for (auto node : graph[curNode]) {
				if (node.first == s2)
				{
					return curRes * node.second;
				}
				if (node.first != s2 && visited[node.first] == false)
				{
					//curRes *= node.second;
					q.push({ node.first ,curRes * node.second });
				}
			}
		}
		return -1;
	}
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

		//initalize graph
		map<string, vector<pair<string, double>>> graph;


		vector<double> result;
		for (int i = 0; i < values.size(); i++) {
			graph[equations[i][0]].push_back({ equations[i][1], values[i] });
			graph[equations[i][1]].push_back({ equations[i][0], 1 / values[i] });
		}

		// { "a","b" },{ "a","c" },{ "b","a" } ,{ "c","b" },{ "c","a" }
		for (auto q : queries) {
			if (graph[q[0]].empty() || graph[q[1]].empty())
			{
				result.push_back(-1);
				continue;
			}
			if (q[0] == q[1])
			{
				result.push_back(1);
				continue;
			}

			result.push_back(BFS(graph, q[0], q[1]));

		}
		return result;
	}
};