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
    void solve(TreeNode* n,int& c){
        if(n == nullptr) return;
        c++;
        solve(n->right,c);
        solve(n->left,c); 
    }
    int countNodes(TreeNode* root) {
        int result = 0;
        solve(root,result); 
        return result;
    }
};