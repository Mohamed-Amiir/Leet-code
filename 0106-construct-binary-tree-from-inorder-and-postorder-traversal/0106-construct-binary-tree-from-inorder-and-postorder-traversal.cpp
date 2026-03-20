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
    unordered_map<int, int> mp;
    int postorderIndx;
    TreeNode* build(vector<int>& postorder, int start, int end) {
        if (start > end)
            return nullptr;
        int rootVal = postorder[postorderIndx--];
        TreeNode* root = new TreeNode(rootVal);

        int rootIndx = mp[rootVal];

        root->right = build(postorder, rootIndx + 1, end);
        root->left = build(postorder, start, rootIndx - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        postorderIndx = postorder.size() - 1;
        return build(postorder, 0, inorder.size() - 1);
    }
};