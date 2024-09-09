class Solution {
public:
	vector<Node> result;
	map<int, char> colors;

	Node* BFS(Node* node, Node* root) {

		Node* curNode = new Node();
		Node* resNode = new Node();
		queue<Node*> input;
		queue<Node*> result;
		input.push(node);
		result.push(root);

		map<int, Node*> cloned;
		cloned[root->val] = root;

		while (!input.empty())
		{
			curNode = input.front();
			resNode = result.front();
			input.pop();
			result.pop();

			for (auto n : curNode->neighbors) {
				if (colors[n->val] == 'W')
				{
					colors[n->val] = 'G';
					Node* newNode = new Node(n->val);

					resNode->neighbors.push_back(newNode);
					newNode->neighbors.push_back(resNode);
					cloned[n->val] = newNode;
					result.push(newNode);
					input.push(n);
				}
				else if(colors[n->val] == 'G')
				{
					resNode->neighbors.push_back(cloned[n->val]);
					cloned[n->val]->neighbors.push_back(resNode);
				}
			}
			colors[resNode->val] = 'B';
		}
		return root;
	}

	Node* cloneGraph(Node* node) {
		if (node == nullptr) {
			return nullptr; 
		}
		for (int i = 0; i <= 100; i++) {
			colors[i] = 'W';
		}

		Node* root = new Node(node->val);

		return BFS(node, root);

	}
};
