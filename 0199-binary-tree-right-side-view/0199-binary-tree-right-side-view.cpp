/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> result;
    void bfs(TreeNode* node) {
        if (!node)
            return;
        queue<TreeNode*> q;
        q.push(node);
        while (!q.empty()) {
            int n = q.size();

            result.push_back(q.front()->val);
            for (int i = 0; i < n; i++) {
                TreeNode* head = q.front();
                q.pop();

                if (head->right)
                    q.push(head->right);
                if (head->left)
                    q.push(head->left);
            }
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        bfs(root);
        return result;
    }
};