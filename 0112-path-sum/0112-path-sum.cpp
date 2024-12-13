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
    bool solve(int curSum, int target,TreeNode* n1,TreeNode* n2){
        // if(curSum == target) return true;
        if(n1 == nullptr && n2 == nullptr) return curSum == target;
        if(n1 != nullptr && n2 == nullptr)
           return solve(curSum + n1->val, target , n1->right , n1->left) ;
        else if(n1 == nullptr && n2 != nullptr)
           return solve(curSum+n2->val,target,n2->right,n2->left);
        else
           return solve(curSum + n1->val, target , n1->right , n1->left) || solve(curSum+n2->val,target,n2->right,n2->left);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        return solve(root->val , targetSum, root->right, root->left);       
    }
};