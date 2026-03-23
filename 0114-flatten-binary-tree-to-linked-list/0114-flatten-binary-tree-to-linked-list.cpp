/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* result = new TreeNode();
    TreeNode* itr = result;

    void preorder(TreeNode* root ){
        if(!root) return;

        itr->right = root;
        itr = itr->right;

        TreeNode* left = root->left;
        TreeNode* right = root->right;

        root->left = nullptr;

        preorder(left);
        preorder(right);
    }

    void flatten(TreeNode* root) {
        preorder(root);
    }
};