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
void dfs(TreeNode* node, vector<int>& digits, vector<int>& nums) {
    if (!node) return;

    digits.push_back(node->val);

    if (!node->left && !node->right) {
        int n = digits.size(), num = 0;;long long d = 1;
        for (int i = n - 1; i >= 0; i--) {
            num += d * digits[i];
            d *= 10;
        }
        nums.push_back(num);
        digits.pop_back(); // fix 1
        return;
    }

    dfs(node->left, digits, nums);
    dfs(node->right, digits, nums);

    digits.pop_back(); // fix 2
}
    int sumNumbers(TreeNode* root) {
        vector<int> digits, nums;
        dfs(root, digits, nums);
        int sum = 0;
        for (int x : nums) {
            // cout << x << endl;
            sum += x;
        }
        return sum;
    }
};