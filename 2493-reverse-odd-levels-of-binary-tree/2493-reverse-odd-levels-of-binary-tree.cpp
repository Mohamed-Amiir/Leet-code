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
// class Solution {
// public:

//     void solve(queue<TreeNode*> q,stack<int>& vals,int levelSize){
//         if(levelSize == 1)return ;
//         while(!q.empty() && levelSize--){
//             TreeNode* cur = q.front();
//             cur->val = vals.top();
//             q.pop();
//             vals.pop();
//         }
//     }
//     TreeNode* reverseOddLevels(TreeNode* root) {
//         TreeNode* result = root;;
//         queue<TreeNode*> q;
//         stack<int> vals;
//         int level = 0,levelSize = 1,c = 1;
//         q.push(root);
//         while(!q.empty()){
//             TreeNode* temp = q.front();
//             // cout << temp->val << " ";
//             q.pop();
//             if(temp->left != nullptr){
//                 q.push(temp->left);
//                 vals.push(temp->left->val);
//                 c++;
//             }
//             if(temp->right != nullptr){
//                 q.push(temp->right);
//                 vals.push(temp->right->val);
//                 c++;
//             }
//             cout << "C: "<<c<<"Level: "<<level<<" "<<"Level Size: "<<levelSize<<endl;
//             if(c == levelSize)
//             {
//                 level++;
//                 levelSize *= 2;
//                 cout << "C: "<<c<<"Level: "<<level<<" "<<"Level Size: "<<levelSize<<endl;
//                 if(level % 2 != 0){
//                     solve(q,vals,levelSize);
//                 }
//             }

//         }
//         return root;
//     }
// };

class Solution {
public:
    void invertTreeHelper(TreeNode* right, TreeNode* left, int level) {
        if (left == nullptr) {
            return;
        }

        // If the current level is odd, invert the children
        if (level % 2 != 0) {
            int leftVal = left->val;
            int rightVal = right->val;
            left->val = rightVal;
            right->val = leftVal;
        }

        // Recursively call the left and right children, incrementing the level
        invertTreeHelper(left->right,right->left, level + 1);
        invertTreeHelper(right->right,left->left, level + 1);
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        invertTreeHelper(root->right,root->left, 1);  // Start with level 1
        return root;
    }

};
