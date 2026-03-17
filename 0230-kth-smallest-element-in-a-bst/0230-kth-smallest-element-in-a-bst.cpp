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
    int itr = 0,result = 0;
    void inorder(TreeNode* node,int k){
        if(!node){
           return;
        }
        inorder(node->left,k);
        itr++;
        if(itr == k ){
            result = node->val;
        }
        inorder(node->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root,k);
        return result;
    }
};