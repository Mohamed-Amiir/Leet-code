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
class FindElements {
public:
    TreeNode* newTree = new TreeNode(0);
    unordered_set<int> nums;
    void solve(TreeNode* node,int value){
        node->val = value;
        nums.insert(value);
        if(node->right == nullptr && node->left == nullptr)return;
        if(node->left != nullptr){
            int leftVal = 2 * value + 1;
            solve(node->left,leftVal);
        }
        if(node->right != nullptr){
            int rightVal = 2 * value + 2;
            solve(node->right,rightVal);
        }
    }

    FindElements(TreeNode* root) {
        solve(root,0);
        newTree = root;
    }
    
    bool search(TreeNode* node,int target){
        if(node == nullptr)return 0;
        if(node->val == target)return true;
        else return search(node->right,target) || search(node->left,target);
    }

    bool find(int target) {
        return nums.count(target) != 0;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */