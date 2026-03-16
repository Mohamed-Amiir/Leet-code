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
    int result = 1e9;
    void bfs(TreeNode* root) {
        if (!root)
            return;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->right) {
                q.push(node->right);
                result = min(result, abs(node->val - node->right->val));
            }
            if (node->left) {
                q.push(node->left);
                result = min(result, abs(node->val - node->left->val));
            }
        }
    }
    int getMinimumDifference(TreeNode* root) {
        bfs(root);
        return result;
    }
};