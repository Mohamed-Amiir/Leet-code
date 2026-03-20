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
    vector<vector<int>> result;
    void bfs(TreeNode* node) {
        if (!node)
            return;
        queue<TreeNode*> q;
        q.push(node);
        while (!q.empty()) {
            int s = q.size();
            vector<int> v;
            for (int i = 0; i < s; i++) {
                TreeNode* temp = q.front();
                q.pop();
                v.push_back(temp->val);
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            result.push_back(v);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        bfs(root);
        return result;
    }
};