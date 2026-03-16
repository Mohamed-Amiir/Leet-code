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
    int result = 1e9, prev = -1;
    void inorder(TreeNode* root) {
        if (!root)
            return;

        inorder(root->left);
        cout << root->val << " ";
        if (prev != -1)
            result = min(result, abs(root->val- prev));
        prev = root->val;
        inorder(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return result;
    }
};