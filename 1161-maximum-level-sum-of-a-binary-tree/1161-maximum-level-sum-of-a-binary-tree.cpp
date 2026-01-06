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
    int maxLevelSum(TreeNode* root) {
        int sum = -1e5+2, level = 0, result = 0;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size(), curSum = 0;
            for (int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                curSum += temp->val;
                q.pop();
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            level++;
            if (sum < curSum) {
                sum = curSum;
                result = level;
            }
        }
        return result;
    }
};