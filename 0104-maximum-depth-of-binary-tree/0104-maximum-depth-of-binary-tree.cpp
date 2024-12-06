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

    int check(TreeNode* tempRoot,int c) {
        if (tempRoot == nullptr)
            return c;
        return max(check(tempRoot->right,c+1),check(tempRoot->left, c+1));
    }

	int maxDepth(TreeNode* root) {
        // int c = 0;
        return check(root, 0);
	}
};