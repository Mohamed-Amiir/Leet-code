class Solution {
public:
    int result = INT_MAX;
    TreeNode* prev = nullptr;

    void inorder(TreeNode* node) {
        if (!node) return;

        inorder(node->left);

        if (prev)
            result = min(result, node->val - prev->val);

        prev = node;
        inorder(node->right);
    }

    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return result;
    }
};