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
    bool explore(TreeNode* node, long long minRange, long long maxRange) {
        if (!node)
            return true;

        if (node->val > minRange && node->val < maxRange) {
            return explore(node->right, node->val, maxRange) &&
                   explore(node->left, minRange, node->val);
        }

        return false;
    }
    bool isValidBST(TreeNode* root) {
        return explore(root, LLONG_MIN, LLONG_MAX);
    }
};