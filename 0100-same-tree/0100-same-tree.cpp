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
    bool checkTree(TreeNode* t1, TreeNode* t2){
        if (!t1 && !t2) return true; 
        if (!t1 || !t2) return false;
         if(t1->val != t2->val)
            return false;
         return checkTree(t1->left,t2->left) && checkTree(t1->right,t2->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return checkTree(p,q);
    }
};