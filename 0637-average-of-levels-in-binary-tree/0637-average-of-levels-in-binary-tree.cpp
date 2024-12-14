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
    // void solve(TreeNode* l,TreeNode* r,vector<double>& result){

    //     if(n == nullptr) return;
    //     double x ,y;
    //     int c = 2;
    //     if(n->right == nullptr){
    //        x = 0;
    //        c--;
    //     }
    //     else{
    //       x = n->right->val;
    //     }
    //     if( n->left == nullptr){
    //        y = 0;
    //        c--;
    //     }
    //     else{
    //       y = n->left->val;
    //     }
    //     if(c == 0) return;
    //     double avg = (x+y)/c;
    //     if(avg != 0)result.push_back(avg);
    //     solve(n->right,result);
    //     solve(n->left,result);
    // }
    // vector<double> averageOfLevels(TreeNode* root) {
    //     vector<double> result;
    //     unordered_map<int,bool> visited;
    //     for()
    //     result.push_back(root->val);
    //     solve(root->right,root->left,result);
    //     return result;
    // }
    vector<double> averageOfLevels(TreeNode* root) {

        vector<double> result;
        if (!root) {
            return result; // Handle empty tree
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size(); // Number of nodes at the current level
            double currentLevel = 0;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();

                currentLevel+=node->val;

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            result.push_back(currentLevel/levelSize);
        }

        return result;

    }
};