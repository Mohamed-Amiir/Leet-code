class Solution {
public:
    map<int, vector<int>> graph;
    map<int, bool> visited;

    long long dfs(int current, vector<int>& values, int k, int& result) {
        visited[current] = true;
        long long currSum = values[current]; // Use long long to store the sum

        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                long long childSum = dfs(neighbor, values, k, result);
                if (childSum % k == 0) {
                    result++; // Increment result as this subtree can form a separate component
                } else {
                    currSum += childSum; // Add the sum of the subtree to the current node
                }
            }
        }

        return currSum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        // Construct the graph
        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        int result = 0; // Count of k-divisible components
        dfs(0, values, k, result);

        // Add 1 for the root component
        return result + 1;
    }
};
